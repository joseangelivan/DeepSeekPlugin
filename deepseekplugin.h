#pragma once

#include <extensionsystem/iplugin.h>
#include "deepseekwidget.h"
#include "deepseektool.h"
#include "deepseekprojectgenerator.h"
#include "deepseekcodeeditor.h"

namespace DeepSeekAI {
namespace Internal {

class DeepSeekPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "DeepSeekPlugin.json")

public:
    DeepSeekPlugin();
    ~DeepSeekPlugin() override;

    bool initialize(const QStringList &arguments, QString *errorString) override;
    void extensionsInitialized() override;
    ShutdownFlag aboutToShutdown() override;

    DeepSeekCodeEditor *codeEditor() const { return m_codeEditor; }
    DeepSeekTool *tool() const { return m_tool; }

private slots:
    void showWidget();

private:
    void initializeMenu();
    void setupConnections();

    DeepSeekTool *m_tool = nullptr;
    DeepSeekProjectGenerator *m_projectGenerator = nullptr;
    DeepSeekWidget *m_widget = nullptr;
    DeepSeekCodeEditor *m_codeEditor = nullptr;
};

} // namespace Internal
} // namespace DeepSeekAI
