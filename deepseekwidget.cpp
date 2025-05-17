#include "deepseekwidget.h"
#include "deepseekplugin.h"
#include "deepseektool.h"
#include "deepseekprojectgenerator.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>

namespace DeepSeekAI {
namespace Internal {

DeepSeekWidget::DeepSeekWidget(QWidget *parent)
    : QWidget(parent),
      m_promptEdit(new QPlainTextEdit(this)),
      m_responseEdit(new QPlainTextEdit(this)),
      m_generateCodeButton(new QPushButton(tr("Generate Code"), this)),
      m_fixCodeButton(new QPushButton(tr("Fix Code"), this)),
      m_generateProjectButton(new QPushButton(tr("Generate Project"), this)),
      m_projectTypeCombo(new QComboBox(this)),
      m_buildSystemCombo(new QComboBox(this)),
      m_progressBar(new QProgressBar(this)),
      m_stackedWidget(new QStackedWidget(this)),
      m_statusLabel(new QLabel(this))
{
    setupUI();

    // Verificar estado inicial de la API Key
    QTimer::singleShot(0, this, [this]() {
        bool apiKeyValid = !m_tool->apiKey().isEmpty();
        onSettingsChanged(apiKeyValid);  // Usa el nuevo nombre
    });
}

DeepSeekWidget::~DeepSeekWidget()
{
}

void DeepSeekWidget::initialize(DeepSeekTool *tool,
                              DeepSeekProjectGenerator *projectGenerator,
                              DeepSeekPlugin *plugin)
{
    m_tool = tool;
    m_projectGenerator = projectGenerator;
    m_plugin = plugin;
    setupConnections();
}

void DeepSeekWidget::prepareShutdown()
{
    // Save any persistent settings if needed
}

void DeepSeekWidget::setupUI()
{
    // Main Layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Prompt Section
    QLabel *promptLabel = new QLabel(tr("Prompt:"), this);
    m_promptEdit->setPlaceholderText(tr("Describe what you want to generate..."));
    mainLayout->addWidget(promptLabel);
    mainLayout->addWidget(m_promptEdit);



    // Añadir botón de configuración
    m_settingsButton = new QToolButton(this);
    m_settingsButton->setIcon(QIcon(":/deepseekplugin/icons/settings.svg"));
    m_settingsButton->setToolTip(tr("Settings"));
    m_settingsButton->setAutoRaise(true);

    // Action Buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(m_generateCodeButton);
    buttonLayout->addWidget(m_fixCodeButton);
    buttonLayout->addWidget(m_generateProjectButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_settingsButton);


    mainLayout->addLayout(buttonLayout);

    // Conectar la señal
    connect(m_settingsButton, &QToolButton::clicked,
            this, &DeepSeekWidget::onSettingsClicked);


    // Project Configuration (initially hidden)
    QFormLayout *projectConfigLayout = new QFormLayout();
    projectConfigLayout->addRow(tr("Project Type:"), m_projectTypeCombo);
    projectConfigLayout->addRow(tr("Build System:"), m_buildSystemCombo);

    QWidget *projectConfigWidget = new QWidget(this);
    projectConfigWidget->setLayout(projectConfigLayout);
    projectConfigWidget->hide();

    mainLayout->addWidget(projectConfigWidget);

    // Response Section
    QLabel *responseLabel = new QLabel(tr("Response:"), this);
    m_responseEdit->setReadOnly(true);
    mainLayout->addWidget(responseLabel);
    mainLayout->addWidget(m_responseEdit);

    // Status Bar
    m_progressBar->setRange(0, 100);
    m_progressBar->setVisible(false);
    mainLayout->addWidget(m_progressBar);
    mainLayout->addWidget(m_statusLabel);

    // Initialize Comboboxes
    m_projectTypeCombo->addItems(DeepSeekProjectGenerator::availableProjectTypes());
    m_buildSystemCombo->addItems(DeepSeekProjectGenerator::availableBuildSystems());
}


// Implementación del slot
void DeepSeekWidget::onSettingsClicked()
{
    if (!m_tool) {
        QMessageBox::warning(this, tr("Error"), tr("Tool not initialized"));
        return;
    }

    // Mostrar diálogo de configuración
    m_tool->showSettingsDialog(this);

    // Opcional: Actualizar estado después de cambiar configuraciones
    // emit settingsChanged();
}


// void DeepSeekWidget::updateUiAfterSettingsChange()
// {
//     bool hasApiKey = !m_tool->apiKey().isEmpty();
//     m_generateCodeButton->setEnabled(hasApiKey);
//     m_fixCodeButton->setEnabled(hasApiKey);

//     if (!hasApiKey) {
//         m_responseEdit->setPlainText(tr("Please configure your API key in settings first"));
//     }
// }

void DeepSeekWidget::setupConnections()
{
    connect(m_generateCodeButton, &QPushButton::clicked,
            this, &DeepSeekWidget::onGenerateCodeClicked);
    connect(m_fixCodeButton, &QPushButton::clicked,
            this, &DeepSeekWidget::onFixCodeClicked);
    connect(m_generateProjectButton, &QPushButton::clicked,
            this, &DeepSeekWidget::onGenerateProjectClicked);
    connect(m_buildSystemCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &DeepSeekWidget::onBuildSystemChanged);

    connect(m_tool, &DeepSeekTool::projectAnalysisReady,
            this, &DeepSeekWidget::handleAnalysisResults);
}

// Implementación del slot
void DeepSeekWidget::handleAnalysisResults(const QJsonObject &results) {
    QJsonObject analysis = results.value("analysis").toObject();

    // Ejemplo: Mostrar en QPlainTextEdit
    QString displayText;
    for (const QString &section : analysis.keys()) {
        displayText += "🔹 " + section + "\n";
        QJsonObject items = analysis[section].toObject();
        for (const QString &key : items.keys()) {
            displayText += QString("  • %1: %2\n").arg(key, items[key].toString());
        }
    }

    m_responseEdit->setPlainText(displayText);

    // Opcional: Mostrar métricas
    QJsonObject metrics = results.value("metrics").toObject();
    m_statusLabel->setText(
        QString("Análisis completado: %1 secciones, %2 líneas")
            .arg(metrics["sections"].toInt())
            .arg(metrics["lines"].toInt())
        );
}

void DeepSeekWidget::updateGenerateProjectUI()
{
    bool showConfig = m_generateProjectButton->isChecked();
    m_projectTypeCombo->parentWidget()->setVisible(showConfig);
    m_buildSystemCombo->parentWidget()->setVisible(showConfig);

    if (showConfig) {
        m_statusLabel->setText(tr("Configure project settings..."));
    } else {
        m_statusLabel->clear();
    }
}

QString DeepSeekWidget::getCurrentBuildSystem() const
{
    return m_buildSystemCombo->currentText();
}

void DeepSeekWidget::onGenerateCodeClicked()
{
    const QString prompt = m_promptEdit->toPlainText().trimmed();
    if (prompt.isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("Please enter a prompt"));
        return;
    }

    m_progressBar->setVisible(true);
    emit requestGenerated(prompt, "code");
}

void DeepSeekWidget::onFixCodeClicked()
{
    if (!m_plugin || !m_plugin->codeEditor()) {
        QMessageBox::warning(this, tr("Error"), tr("Editor not available"));
        return;
    }

    if (!m_plugin->codeEditor()->hasActiveEditor()) {
        QMessageBox::warning(this, tr("Error"), tr("No active editor found"));
        return;
    }

    const QString prompt = m_promptEdit->toPlainText().trimmed();
    if (prompt.isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("Please describe the issue to fix"));
        return;
    }

    const QString currentCode = m_plugin->codeEditor()->currentFileContent();
    m_progressBar->setVisible(true);
    emit requestFixCode(currentCode, prompt);
}

void DeepSeekWidget::onGenerateProjectClicked()
{
    updateGenerateProjectUI();

    if (!m_generateProjectButton->isChecked()) {
        return;
    }

    QString projectName = "NewProject";
    QString projectPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    projectPath = QFileDialog::getExistingDirectory(this, tr("Select Project Directory"), projectPath);

    if (projectPath.isEmpty()) {
        m_generateProjectButton->setChecked(false);
        updateGenerateProjectUI();
        return;
    }

    auto buildSystem = static_cast<DeepSeekProjectGenerator::BuildSystem>(
        m_buildSystemCombo->currentIndex());

    emit requestProjectGeneration(
        projectName,
        projectPath,
        buildSystem,
        m_projectTypeCombo->currentText(),
        m_promptEdit->toPlainText().trimmed()
    );
}

void DeepSeekWidget::onBuildSystemChanged(int index)
{
    Q_UNUSED(index)
    // Update any build-system specific UI if needed
}

void DeepSeekWidget::onResponseReceived(const QString &response)
{
    m_responseEdit->setPlainText(response);
    m_progressBar->setVisible(false);
}

void DeepSeekWidget::onErrorOccurred(const QString &error)
{
    m_responseEdit->appendPlainText(tr("Error: %1").arg(error));
    m_progressBar->setVisible(false);
}

void DeepSeekWidget::onProgressChanged(int progress){
    m_progressBar->setValue(progress);
}

void DeepSeekWidget::onProjectGenerated(const QString &projectPath){
    m_responseEdit->appendPlainText(tr("Project created at: %1").arg(projectPath));
    m_progressBar->setVisible(false);
    m_generateProjectButton->setChecked(false);
    updateGenerateProjectUI();
}

void DeepSeekWidget::onSettingsChanged(bool apiKeyValid) {
    // Actualizar UI basado en la validez de la API Key
    m_generateCodeButton->setEnabled(apiKeyValid);
    m_fixCodeButton->setEnabled(apiKeyValid);

    if (!apiKeyValid) {
        m_responseEdit->setPlainText(tr("⚠️ Please set your API Key in Settings"));
    }
}

} // namespace Internal
} // namespace DeepSeekAI
