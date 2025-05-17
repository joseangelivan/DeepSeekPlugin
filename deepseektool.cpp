#include "deepseektool.h"
#include "deepseekpluginconstants.h"

#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonArray>
#include <QSettings>
#include <QCoreApplication>
#include <QTimer>
#include <QThread>
#include <QInputDialog>

#include "messagehelper.h" // Si usas el helper
#include <coreplugin/messagemanager.h>

namespace DeepSeekAI {
namespace Internal {

DeepSeekTool::DeepSeekTool(QObject *parent)
    : QObject(parent),
      m_networkManager(new QNetworkAccessManager(this)),
      m_baseUrl("https://api.deepseek.com/v1"),
      m_isInitialized(false)
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    // m_apiKey = settings.value("DeepSeek/ApiKey").toString();
    // Cargar la API Key al iniciar
    m_apiKey = DeepSeekSettingsDialog::loadApiKey();
}

DeepSeekTool::~DeepSeekTool()
{
    m_networkManager->deleteLater();
}

void DeepSeekTool::initialize()
{
    if (m_isInitialized) {
        return;
    }

    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &DeepSeekTool::onRequestFinished);

    connect(m_networkManager, &QNetworkAccessManager::sslErrors,
            this, &DeepSeekTool::onSslErrors);

    m_isInitialized = true;
}

void DeepSeekTool::setApiKey(const QString &apiKey)
{
    if (m_apiKey != apiKey) {
        m_apiKey = apiKey;
        QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
        settings.setValue("DeepSeek/ApiKey", m_apiKey);
    }
}

QString DeepSeekTool::apiKey() const
{
    return m_apiKey;
}

void DeepSeekTool::showSettingsDialog(QWidget *parent)
{
    DeepSeekSettingsDialog dialog(parent);
    dialog.setApiKey(m_apiKey);

    if (dialog.exec() == QDialog::Accepted) {
        QString newApiKey = dialog.apiKey();
        if (newApiKey != m_apiKey) {
            m_apiKey = newApiKey;
            DeepSeekSettingsDialog::saveApiKey(m_apiKey);

            // Emitir señal con el estado de la API Key (true si es válida)
            emit settingsChanged(!m_apiKey.isEmpty());

            Core::MessageManager::writeFlashing(
                m_apiKey.isEmpty()
                    ? "[DeepSeek] API Key removed"
                    : "[DeepSeek] API Key updated"
                );
        }
    }

    // DeepSeekSettingsDialog dialog(parent);
    // dialog.setApiKey(m_apiKey);

    // if (dialog.exec() == QDialog::Accepted) {
    //     m_apiKey = dialog.apiKey();
    //     DeepSeekSettingsDialog::saveApiKey(m_apiKey);
    //     emit settingsChanged();
    // }
}

void DeepSeekTool::sendRequest(const QString &prompt, const QString &mode)
{
    // if (!m_isInitialized) {
    //     emit errorOccurred(tr("DeepSeekTool not initialized"));
    //     return;
    // }

    // if (m_apiKey.isEmpty()) {
    //     emit errorOccurred(tr("API Key not configured"));
    //     return;
    // }

    // if (prompt.isEmpty()) {
    //     emit errorOccurred(tr("Prompt cannot be empty"));
    //     return;
    // }



    // QUrl apiUrl(m_baseUrl + getEndpointForMode(mode));
    // QNetworkRequest request(apiUrl);

    // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    // if (!m_apiKey.isEmpty()) {
    //     request.setRawHeader("Authorization", QString("Bearer %1").arg(m_apiKey).toUtf8());
    // }

    // QJsonObject payload = buildPayload(prompt);
    // QJsonDocument doc(payload);
    // QByteArray data = doc.toJson();

    // QNetworkReply *reply = m_networkManager->post(request, data);
    // connect(reply, &QNetworkReply::errorOccurred,
    //         this, &DeepSeekTool::onNetworkError);

    // emit progressChanged(10);


    // 1. Validación de API Key
    if (m_apiKey.isEmpty()) {
        Utils::MessageHelper::showMessage(
            tr("API Key no configurada. Vaya a DeepSeek > Settings"),
            Utils::MessageHelper::Disrupt
            );
        emit errorOccurred(tr("Configuración requerida"));
        return;
    }

    // 2. Mostrar estado de progreso
    emit progressChanged(10);
    Utils::MessageHelper::showMessage(
        tr("Procesando solicitud: %1").arg(mode),
        Utils::MessageHelper::Silent
        );

    // 3. Configurar la solicitud HTTP
    QNetworkRequest request(QUrl("https://api.deepseek.com/v1/chat/completions"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(m_apiKey).toUtf8());

    // 4. Construir cuerpo JSON según el modo
    QJsonObject json;
    json["model"] = "deepseek-chat";

    if (mode == "fix") {
        json["messages"] = QJsonArray({
            QJsonObject({
                {"role", "system"},
                {"content", "Eres un asistente de corrección de código. Proporciona SOLO el código corregido sin explicaciones adicionales."}
            }),
            QJsonObject({
                {"role", "user"},
                {"content", prompt}
            })
        });
    } else {
        json["messages"] = QJsonArray({
            QJsonObject({
                {"role", "user"},
                {"content", prompt}
            })
        });
    }

    json["temperature"] = 0.7;
    json["max_tokens"] = 2000;

    // 5. Enviar solicitud asíncrona con timeout
    QNetworkReply *reply = m_networkManager->post(request, QJsonDocument(json).toJson());
    reply->setProperty("requestMode", mode);  // Almacena el modo

    QTimer timeoutTimer;
    timeoutTimer.setSingleShot(true);
    QEventLoop loop;

    // 6. Configurar timeout (30 segundos)
    timeoutTimer.start(30000);
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    connect(&timeoutTimer, &QTimer::timeout, [&]() {
        if (reply->isRunning()) {
            reply->abort();
            Utils::MessageHelper::showMessage(
                tr("Timeout: La solicitud excedió el tiempo límite"),
                Utils::MessageHelper::Disrupt
                );
        }
    });

    // 7. Manejar respuesta
    connect(reply, &QNetworkReply::finished, this, [this, reply, mode, &loop]() {
        if (reply->error() != QNetworkReply::NoError) {
            handleNetworkError(reply);
            loop.quit();
            return;
        }

        QJsonDocument response = QJsonDocument::fromJson(reply->readAll());
        processApiResponse(response, mode);
        loop.quit();
    });

    loop.exec();

    // 8. Limpieza
    reply->deleteLater();
    emit progressChanged(100);
}

void DeepSeekTool::handleNetworkError(QNetworkReply *reply)
{
    QString errorMsg;
    switch (reply->error()) {
    case QNetworkReply::TimeoutError:
        errorMsg = tr("Timeout al conectar con DeepSeek API");
        break;
    case QNetworkReply::AuthenticationRequiredError:
        errorMsg = tr("API Key inválida. Verifique en Settings");
        break;
    default:
        errorMsg = tr("Error de red: %1").arg(reply->errorString());
    }

    Utils::MessageHelper::showMessage(errorMsg, Utils::MessageHelper::Disrupt);
    emit errorOccurred(errorMsg);
    emit progressChanged(0);
}

void DeepSeekTool::requestFix(const QString &code, const QString &problemDescription)
{
    QString prompt = QString("Fix the following code:\n\n%1\n\nProblem: %2\n\n"
                           "Provide only the complete fixed code without additional explanations.")
                    .arg(code)
                    .arg(problemDescription);

    sendRequest(prompt, "fix");
}

void DeepSeekTool::requestProjectAnalysis(const QMap<QString, QString> &projectContents)
{
    QString prompt = "Analyze this Qt project and provide:\n";
    prompt += "1. Architecture suggestions\n";
    prompt += "2. Performance improvements\n";
    prompt += "3. Modern Qt practices to apply\n";
    prompt += "4. Potential bugs\n\n";
    prompt += "Project structure:\n";

    for (const QString &filePath : projectContents.keys()) {
        prompt += "- " + filePath + "\n";
    }

    prompt += "\nKey files content:\n";
    int fileCount = 0;
    for (const auto &[path, content] : projectContents.asKeyValueRange()) {
        if (fileCount++ > 10) break; // Limit to 10 files to avoid huge prompts
        if (path.endsWith(".cpp") || path.endsWith(".h") || path.endsWith(".qml")) {
            prompt += QString("\n==== %1 ====\n%2\n").arg(path).arg(content.left(1000));
        }
    }

    sendRequest(prompt, "analysis");
}

void DeepSeekTool::onRequestFinished(QNetworkReply *reply)
{
    reply->deleteLater();
    emit progressChanged(90);

    // Manejo de errores mejorado
    if (reply->error() != QNetworkReply::NoError) {
        handleNetworkError(reply);  // Usa la función de manejo de errores existente
        emit progressChanged(0);
        return;
    }

    // Obtener el modo del userData (más seguro que de la URL)
    QString mode = reply->property("requestMode").toString();

    // Procesar respuesta
    QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
    if (jsonResponse.isNull()) {
        emit errorOccurred(tr("Respuesta JSON inválida"));
        emit progressChanged(0);
        return;
    }

    processApiResponse(jsonResponse, mode);  // Nueva función
    emit progressChanged(100);
}

void DeepSeekTool::onSslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply)
    QStringList errorStrings;
    for (const QSslError &error : errors) {
        errorStrings.append(error.errorString());
    }
    emit errorOccurred(tr("SSL errors occurred: %1").arg(errorStrings.join(", ")));
}

// void DeepSeekTool::onNetworkError(QNetworkReply::NetworkError code)
// {
//     Q_UNUSED(code)
//     auto *reply = qobject_cast<QNetworkReply*>(sender());
//     if (reply) {
//         emit errorOccurred(reply->errorString());
//     }
// }

void DeepSeekTool::processApiResponse(const QJsonDocument &response, const QString &mode) {
    // // 1. Validación estricta
    // if (!response.isObject()) {
    //     emit errorOccurred(tr("Respuesta no es objeto JSON"));
    //     return;
    // }

    // QJsonObject obj = response.object();
    // if (!obj.contains("choices") || !obj["choices"].isArray()) {
    //     emit errorOccurred(tr("Formato de respuesta inválido (falta 'choices')"));
    //     return;
    // }

    // QJsonArray choices = obj["choices"].toArray();
    // if (choices.isEmpty()) {
    //     emit errorOccurred(tr("La API no devolvió resultados"));
    //     return;
    // }

    // // 2. Extracción segura con value()
    // QString content = choices.first().toObject()
    //                       .value("message").toObject()
    //                       .value("content").toString();

    // if (content.isEmpty()) {
    //     emit errorOccurred(tr("Contenido vacío en la respuesta"));
    //     return;
    // }

    // // 3. Manejo de modos con enum (más seguro que strings)
    // if (mode == "fix") {
    //     emit fixReady(content);
    // } else if (mode == "analysis") {
    //     emit projectAnalysisReady(parseAnalysis(content)); // Procesamiento adicional
    // } else { // "generate" o cualquier otro
    //     emit responseReceived(content);
    // }

    // // 4. Notificación profesional
    // Utils::MessageHelper::showMessage(
    //     QString("%1 completado: %2 caracteres")
    //         .arg(mode == "fix" ? "Corrección" : "Generación")
    //         .arg(content.length()),
    //     Utils::MessageHelper::Flash
    //     );

    // 1. Validación básica del JSON
    if (!response.isObject()) {
        emit errorOccurred(tr("Invalid JSON response format"));
        Utils::MessageHelper::showMessage(
            "Error: La respuesta no es un objeto JSON válido",
            Utils::MessageHelper::Disrupt
            );
        return;
    }

    QJsonObject obj = response.object();

    // 2. Validar estructura esperada de la API
    if (!obj.contains("choices") || !obj["choices"].isArray()) {
        QString errorMsg = tr("API response missing 'choices' array");
        emit errorOccurred(errorMsg);
        Utils::MessageHelper::showMessage(
            QString("Error de API: %1").arg(errorMsg),
            Utils::MessageHelper::Disrupt
            );
        return;
    }

    QJsonArray choices = obj["choices"].toArray();
    if (choices.isEmpty()) {
        emit errorOccurred(tr("Empty choices array in response"));
        return;
    }

    // 3. Extracción segura del contenido
    QJsonObject firstChoice = choices.first().toObject();
    QJsonObject message = firstChoice.value("message").toObject();
    QString content = message.value("content").toString();

    if (content.isEmpty()) {
        emit errorOccurred(tr("Empty content in API response"));
        return;
    }

    // 4. Procesamiento según el modo
    if (mode == "fix") {
        emit fixReady(content.trimmed());
        Utils::MessageHelper::showMessage(
            "✓ Código corregido listo",
            Utils::MessageHelper::Flash
            );
    }
    else if (mode == "analysis") {
        QJsonObject analysisResult = parseAnalysis(content);

        if (analysisResult.value("analysis").toObject().isEmpty()) {
            Utils::MessageHelper::showMessage(
                "⚠️ El análisis no contiene datos estructurados",
                Utils::MessageHelper::Flash
                );
        }

        emit projectAnalysisReady(analysisResult);
        Utils::MessageHelper::showMessage(
            QString("✓ Análisis completado (%1 secciones)")
                .arg(analysisResult["metrics"].toObject()["sections"].toInt()),
            Utils::MessageHelper::Silent
            );
    }
    else { // Modo por defecto (generation)
        emit responseReceived(content.trimmed());
        Utils::MessageHelper::showMessage(
            QString("✓ Generación completada (%1 caracteres)")
                .arg(content.length()),
            Utils::MessageHelper::Flash
            );
    }

    // 5. Registro de depuración (solo en modo debug)
#ifdef QT_DEBUG
    qDebug() << "API Response processed - Mode:" << mode
             << "Content size:" << content.size();
#endif
}

QJsonObject DeepSeekTool::parseAnalysis(const QString &apiResponse) {
    QJsonObject result;
    result["raw"] = apiResponse;  // Guardar respuesta original

    // 1. Parsear estructura básica
    QJsonDocument doc = QJsonDocument::fromJson(apiResponse.toUtf8());
    if (doc.isNull()) {
        Utils::MessageHelper::showMessage(
            "Análisis: Respuesta no es JSON válido",
            Utils::MessageHelper::Disrupt
            );
        return result;
    }

    // 2. Extraer secciones clave (implementación abajo)
    QJsonObject analysis = extractKeySections(apiResponse);
    if (!analysis.isEmpty()) {
        result["analysis"] = analysis;
    }

    // 3. Métricas básicas
    result["metrics"] = QJsonObject({
        {"characters", apiResponse.length()},
        {"lines", apiResponse.count('\n') + 1},
        {"sections", analysis.size()}
    });

    return result;
}

QJsonObject DeepSeekTool::extractKeySections(const QString &content) {
    QJsonObject sections;
    QStringList lines = content.split('\n');

    // Expresiones regulares para detectar secciones
    QRegularExpression sectionRegex(R"(^#{1,3}\s+(.+)$)");
    QRegularExpression keyValueRegex(R"(^- (\w+):\s*(.*)$)");

    QString currentSection;
    QJsonObject currentData;

    for (const QString &line : lines) {
        QRegularExpressionMatch sectionMatch = sectionRegex.match(line);
        if (sectionMatch.hasMatch()) {
            // Guardar sección previa
            if (!currentSection.isEmpty()) {
                sections[currentSection] = currentData;
                currentData = QJsonObject();
            }
            currentSection = sectionMatch.captured(1).trimmed();
            continue;
        }

        QRegularExpressionMatch kvMatch = keyValueRegex.match(line);
        if (kvMatch.hasMatch() && !currentSection.isEmpty()) {
            currentData[kvMatch.captured(1)] = kvMatch.captured(2).trimmed();
        }
    }

    // Añadir última sección
    if (!currentSection.isEmpty()) {
        sections[currentSection] = currentData;
    }

    return sections;
}

// void DeepSeekTool::processResponse(const QByteArray &responseData, const QString &mode)
// {
//     QJsonDocument doc = QJsonDocument::fromJson(responseData);
//     if (doc.isNull()) {
//         emit errorOccurred(tr("Invalid JSON response"));
//         return;
//     }

//     QJsonObject responseObj = doc.object();
//     if (responseObj.contains("error")) {
//         emit errorOccurred(responseObj["error"].toString());
//         return;
//     }

//     if (mode == "fix") {
//         processFixResponse(responseObj);
//     } else if (mode == "analysis") {
//         processAnalysisResponse(responseObj);
//     } else {
//         if (!responseObj.contains("choices") || !responseObj["choices"].isArray()) {
//             emit errorOccurred(tr("Invalid response format"));
//             return;
//         }

//         QJsonArray choices = responseObj["choices"].toArray();
//         if (choices.isEmpty()) {
//             emit errorOccurred(tr("No response from AI"));
//             return;
//         }

//         QString content = choices.first().toObject()["message"].toObject()["content"].toString();
//         emit responseReceived(content);
//     }
// }

// void DeepSeekTool::processFixResponse(const QJsonObject &response)
// {
//     if (!response.contains("choices") || !response["choices"].isArray()) {
//         emit errorOccurred(tr("Invalid fix response format"));
//         return;
//     }

//     QJsonArray choices = response["choices"].toArray();
//     if (choices.isEmpty()) {
//         emit errorOccurred(tr("No fix provided"));
//         return;
//     }

//     QString fixedCode = choices.first().toObject()["message"].toObject()["content"].toString();
//     emit fixReady(fixedCode);
// }

// void DeepSeekTool::processAnalysisResponse(const QJsonObject &response)
// {
//     if (!response.contains("choices") || !response["choices"].isArray()) {
//         emit errorOccurred(tr("Invalid analysis response format"));
//         return;
//     }

//     QJsonArray choices = response["choices"].toArray();
//     if (choices.isEmpty()) {
//         emit errorOccurred(tr("No analysis provided"));
//         return;
//     }

//     QString analysisText = choices.first().toObject()["message"].toObject()["content"].toString();

//     // Parse the analysis into a structured JSON object
//     QJsonObject analysisResult;
//     analysisResult["summary"] = "Project analysis completed";
//     analysisResult["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);

//     QJsonArray suggestions;
//     for (const QString &line : analysisText.split("\n")) {
//         if (line.startsWith("- ") || line.startsWith("* ")) {
//             suggestions.append(line.mid(2));
//         } else if (!line.trimmed().isEmpty()) {
//             suggestions.append(line.trimmed());
//         }
//     }
//     analysisResult["suggestions"] = suggestions;

//     emit projectAnalysisReady(analysisResult);
// }

// QJsonObject DeepSeekTool::buildPayload(const QString &prompt) const
// {
//     QJsonObject payload;
//     payload["model"] = "deepseek-chat";
//     payload["messages"] = QJsonArray({
//         QJsonObject({
//             {"role", "user"},
//             {"content", prompt}
//         })
//     });
//     payload["temperature"] = 0.7;
//     payload["max_tokens"] = 2000;
//     payload["stream"] = false;

//     return payload;
// }

// QString DeepSeekTool::getEndpointForMode(const QString &mode) const
// {
//     if (mode == "fix") {
//         return "/chat/completions";
//     } else if (mode == "analysis") {
//         return "/chat/completions";
//     }
//     return "/chat/completions";
// }

} // namespace Internal
} // namespace DeepSeekAI
