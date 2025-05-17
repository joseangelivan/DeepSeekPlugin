#include "deepseekplugin.h"
#include "deepseekpluginconstants.h"
#include "deepseekplugintr.h"

#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/coreconstants.h>
#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/icore.h>
#include <coreplugin/messagemanager.h>
#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/projecttree.h>
#include <texteditor/texteditor.h>

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QTimer>

using namespace Core;
using namespace ProjectExplorer;
using namespace TextEditor;

namespace DeepSeekAI {
namespace Internal {

DeepSeekPlugin::DeepSeekPlugin()
{
}

DeepSeekPlugin::~DeepSeekPlugin()
{
    delete m_widget;
    delete m_projectGenerator;
    delete m_tool;
    delete m_codeEditor;
}

bool DeepSeekPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    m_tool = new DeepSeekTool(this);
    m_projectGenerator = new DeepSeekProjectGenerator(this);
    m_codeEditor = new DeepSeekCodeEditor(this);
    m_widget = new DeepSeekWidget();

    initializeMenu();
    setupConnections();

    return true;
}

void DeepSeekPlugin::extensionsInitialized()
{
    m_tool->initialize();
    m_projectGenerator->initialize();
    // m_codeEditor->initialize();

    QTimer::singleShot(1000, this, [this]() {
        if (m_widget) {
            m_widget->initialize(m_tool, m_projectGenerator, this);
        }
    });
}

ExtensionSystem::IPlugin::ShutdownFlag DeepSeekPlugin::aboutToShutdown()
{
    if (m_widget) {
        m_widget->prepareShutdown();
    }
    return SynchronousShutdown;
}

void DeepSeekPlugin::initializeMenu()
{
    ActionContainer *menu = ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(Tr::tr("DeepSeek"));
    ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    auto action = new QAction(Tr::tr("DeepSeek Panel"), this);
    Command *cmd = ActionManager::registerAction(action, Constants::ACTION_ID);
    cmd->setDefaultKeySequence(QKeySequence(Tr::tr("Ctrl+Alt+D")));
    connect(action, &QAction::triggered, this, &DeepSeekPlugin::showWidget);
    menu->addAction(cmd);

    // --- NUEVO: Añadir acción de configuración ---
    auto settingsAction = new QAction(Tr::tr("Settings"), this);
    Command *settingsCmd = ActionManager::registerAction(settingsAction, Constants::SETTINGS_ACTION_ID);
    settingsCmd->setDefaultKeySequence(QKeySequence(Tr::tr("Ctrl+Alt+,")));
    connect(settingsAction, &QAction::triggered, this, [this]() {
        // if (auto plugin = DeepSeekPlugin::instance()) {
        //     if (plugin->widget()) {
        //         // Lógica para mostrar el diálogo de configuración
        //         plugin->tool()->showSettingsDialog(ICore::dialogParent());
        //     }
        // }

        if (m_widget) {
            m_tool->showSettingsDialog(ICore::dialogParent());
        }
    });
    menu->addAction(settingsCmd);

    // Separador entre grupos de acciones
    menu->addSeparator();
}

void DeepSeekPlugin::setupConnections()
{
    connect(m_widget, &DeepSeekWidget::requestGenerated,
            m_tool, &DeepSeekTool::sendRequest);

    connect(m_widget, &DeepSeekWidget::requestFixCode,
            m_tool, &DeepSeekTool::requestFix);

    connect(m_tool, &DeepSeekTool::responseReceived,
            m_widget, &DeepSeekWidget::onResponseReceived);

    connect(m_tool, &DeepSeekTool::errorOccurred,
            m_widget, &DeepSeekWidget::onErrorOccurred);

    connect(m_tool, &DeepSeekTool::progressChanged,
            m_widget, &DeepSeekWidget::onProgressChanged);

    connect(m_tool, &DeepSeekTool::fixReady, this, [this](const QString &fixedCode) {
        if (m_codeEditor->hasActiveEditor()) {
            m_codeEditor->replaceCurrentFileContent(fixedCode);
            MessageManager::writeFlashing(
                Tr::tr("Code was automatically fixed by DeepSeek"));
        }
    });

    connect(m_widget, &DeepSeekWidget::requestProjectGeneration,
            m_projectGenerator, &DeepSeekProjectGenerator::generateProject);

    connect(m_projectGenerator, &DeepSeekProjectGenerator::projectGenerated,
            m_widget, &DeepSeekWidget::onProjectGenerated);

    connect(m_projectGenerator, &DeepSeekProjectGenerator::errorOccurred,
            m_widget, &DeepSeekWidget::onErrorOccurred);

    // Conectar la señal de Tool al Widget
    connect(m_tool, &DeepSeekTool::settingsChanged,
            m_widget, &DeepSeekWidget::onSettingsChanged);
}

void DeepSeekPlugin::showWidget()
{
    if (m_widget) {
        m_widget->show();
        m_widget->raise();
        m_widget->activateWindow();
    }
}

} // namespace Internal
} // namespace DeepSeekAI
