#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include "deepseeksettingsdialog.h"
#include <coreplugin/messagemanager.h>

namespace DeepSeekAI {
namespace Internal {

class DeepSeekTool : public QObject
{
    Q_OBJECT

public:
    explicit DeepSeekTool(QObject *parent = nullptr);
    ~DeepSeekTool();

    void initialize();

    void setApiKey(const QString &apiKey);

    QString apiKey() const;

    void showSettingsDialog(QWidget *parent);

public slots:
    void sendRequest(const QString &prompt, const QString &mode);
    void requestFix(const QString &code, const QString &problemDescription);
    void requestProjectAnalysis(const QMap<QString, QString> &projectContents);

signals:
    void responseReceived(const QString &response);
    void fixReady(const QString &fixedCode);
    void projectAnalysisReady(const QJsonObject &analysis);
    void errorOccurred(const QString &error);
    void progressChanged(int progress);
    void settingsChanged(bool apiKeyValid);


private slots:
    void onRequestFinished(QNetworkReply *reply);
    void onSslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
    // void onNetworkError(QNetworkReply::NetworkError code);

private:
    // void processResponse(const QByteArray &responseData, const QString &mode);
    // void processFixResponse(const QJsonObject &response);
    // void processAnalysisResponse(const QJsonObject &response);
    // QJsonObject buildPayload(const QString &prompt) const;
    // QString getEndpointForMode(const QString &mode) const;

    QNetworkAccessManager *m_networkManager;
    QString m_apiKey;
    QString m_baseUrl;
    bool m_isInitialized;
    void handleNetworkError(QNetworkReply *reply);
    void processApiResponse(const QJsonDocument &response, const QString &mode);

    QJsonObject parseAnalysis(const QString &apiResponse);
    QJsonObject extractKeySections(const QString &content);
};

} // namespace Internal
} // namespace DeepSeekAI
