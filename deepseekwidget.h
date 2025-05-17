#pragma once

#include <QWidget>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QToolButton>
#include <QComboBox>
#include <QProgressBar>
#include <QStackedWidget>
#include <QLabel>

#include "deepseekprojectgenerator.h"

namespace DeepSeekAI {
namespace Internal {

class DeepSeekTool;
class DeepSeekProjectGenerator;
class DeepSeekPlugin;

class DeepSeekWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DeepSeekWidget(QWidget *parent = nullptr);
    ~DeepSeekWidget();

    void initialize(DeepSeekTool *tool, DeepSeekProjectGenerator *projectGenerator, DeepSeekPlugin *plugin);
    void prepareShutdown();

public slots:
    void onResponseReceived(const QString &response);
    void onErrorOccurred(const QString &error);
    void onProgressChanged(int progress);
    void onProjectGenerated(const QString &projectPath);

    void onSettingsChanged(bool apiKeyValid);  // Slot para actualizar la UI

    void handleAnalysisResults(const QJsonObject &results);
signals:
    void requestGenerated(const QString &prompt, const QString &mode);
    void requestFixCode(const QString &code, const QString &description);
    void requestProjectGeneration(const QString &projectName,
                                  const QString &projectPath,
                                  DeepSeekProjectGenerator::BuildSystem buildSystem,
                                  const QString &projectType,
                                  const QString &prompt);

private slots:
    void onGenerateCodeClicked();
    void onFixCodeClicked();
    void onGenerateProjectClicked();
    void onBuildSystemChanged(int index);

    // void updateUiAfterSettingsChange();

private:
    void setupUI();
    void setupConnections();
    void updateGenerateProjectUI();
    QString getCurrentBuildSystem() const;
    void onSettingsClicked();

    DeepSeekTool *m_tool = nullptr;
    DeepSeekProjectGenerator *m_projectGenerator = nullptr;
    DeepSeekPlugin *m_plugin = nullptr;

    // UI Elements
    QPlainTextEdit *m_promptEdit;
    QPlainTextEdit *m_responseEdit;
    QPushButton *m_generateCodeButton;
    QPushButton *m_fixCodeButton;
    QPushButton *m_generateProjectButton;
    QComboBox *m_projectTypeCombo;
    QComboBox *m_buildSystemCombo;
    QProgressBar *m_progressBar;
    QStackedWidget *m_stackedWidget;
    QLabel *m_statusLabel;

    QToolButton *m_settingsButton;
};

} // namespace Internal
} // namespace DeepSeekAI
