#include "deepseekprojectgenerator.h"
#include "deepseekpluginconstants.h"

#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/projecttree.h>
#include <projectexplorer/projectmanager.h>
#include <projectexplorer/projectnodes.h>
#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/documentmanager.h>
#include <coreplugin/idocument.h>
#include <utils/fileutils.h>
#include <utils/mimeutils.h>
#include <qtsupport/qtversionmanager.h>
#include <qtsupport/baseqtversion.h>
#include <texteditor/textdocument.h>

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDateTime>
#include <QFutureWatcher>

using namespace ProjectExplorer;
using namespace Utils;
using namespace QtSupport;
using namespace Core;

namespace DeepSeekAI {
namespace Internal {

DeepSeekProjectGenerator::DeepSeekProjectGenerator(QObject *parent)
    : QObject(parent)
{
}

DeepSeekProjectGenerator::~DeepSeekProjectGenerator()
{
}

QStringList DeepSeekProjectGenerator::availableProjectTypes()
{
    return {
        tr("Qt Widgets Application"),
        tr("Qt Quick Application"),
        tr("Console Application"),
        tr("Static Library"),
        tr("Shared Library"),
        tr("Qt Plugin")
    };
}

QStringList DeepSeekProjectGenerator::availableBuildSystems()
{
    return {
        tr("CMake"),
        tr("qmake"),
        tr("Qbs")
    };
}

void DeepSeekProjectGenerator::initialize()
{
}

void DeepSeekProjectGenerator::generateProject(const QString &projectName,
                                             const QString &projectPath,
                                             BuildSystem buildSystem,
                                             const QString &projectType,
                                             const QString &prompt)
{
    QDir dir(projectPath);
    if (!dir.exists() && !dir.mkpath(projectPath)) {
        emit errorOccurred(tr("Failed to create project directory: %1").arg(projectPath));
        return;
    }

    createProjectStructure(projectPath, projectType);

    switch (buildSystem) {
    case CMake:
        generateCMakeProject(projectPath, projectName, projectType, prompt);
        break;
    case QMake:
        generateQMakeProject(projectPath, projectName, projectType, prompt);
        break;
    case Qbs:
        generateQbsProject(projectPath, projectName, projectType, prompt);
        break;
    }

    QString projectFile;
    switch (buildSystem) {
    case CMake:
        projectFile = QString("%1/CMakeLists.txt").arg(projectPath);
        break;
    case QMake:
        projectFile = QString("%1/%2.pro").arg(projectPath).arg(projectName);
        break;
    case Qbs:
        projectFile = QString("%1/%2.qbs").arg(projectPath).arg(projectName);
        break;
    }

    if (!QFileInfo::exists(projectFile)) {
        emit errorOccurred(tr("Failed to generate project file"));
        return;
    }

    emit projectGenerated(projectFile);
}

void DeepSeekProjectGenerator::openAndAnalyzeProject(const QString &projectFilePath)
{
    FilePath filePath = FilePath::fromString(projectFilePath);

    // Solución correcta - obtener el thread pool primero
    QThreadPool* pool = QThreadPool::globalInstance();
    auto future = QtConcurrent::run(pool, [this, filePath]() {
        OpenProjectResult result = ProjectExplorerPlugin::instance()->openProject(filePath);

        if (!result) {
            emit errorOccurred(tr("Failed to open project: %1").arg(result.errorMessage()));
            return;
        }

        Project* project = result.project();
        if (!project) {
            emit errorOccurred(tr("Project opened but invalid"));
            return;
        }

        // Espera activa mejorada
        QElapsedTimer timer;
        timer.start();
        while (!project->rootProjectNode() && timer.elapsed() < 5000) {
            QThread::msleep(100);
            QCoreApplication::processEvents();
        }

        if (!project->rootProjectNode()) {
            emit errorOccurred(tr("Project structure not loaded after timeout"));
            return;
        }

        emit projectOpened(project);

        QMap<QString, QString> projectContents;
        ProjectNode *rootNode = project->rootProjectNode();

        auto processFile = [&projectContents](const FilePath &filePath) {
            QFile file(filePath.toUserOutput());
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream stream(&file);
                projectContents.insert(filePath.toUserOutput(), stream.readAll());
                file.close();
                return true;
            }
            return false;
        };

        rootNode->forEachNode([&](FileNode *node) {
            if (node &&
                (node->fileType() == FileType::Source ||
                 node->fileType() == FileType::Header ||
                 node->fileType() == FileType::QML ||
                 node->fileType() == FileType::Resource)) {
                processFile(node->filePath());
            }
            return true;
        });

        emit projectAnalysisComplete(projectContents);
    });

    auto *watcher = new QFutureWatcher<void>(this);
    connect(watcher, &QFutureWatcher<void>::finished, watcher, &QFutureWatcher<void>::deleteLater);
    watcher->setFuture(future);
}

void DeepSeekProjectGenerator::createProjectStructure(const QString &projectPath, const QString &projectType)
{
    QDir dir(projectPath);

    // Directorios comunes
    dir.mkdir("src");
    dir.mkdir("include");

    // Directorios específicos por tipo de proyecto
    if (projectType == "Qt Widgets Application") {
        dir.mkdir("resources");
        dir.mkdir("forms");
        dir.mkdir("ui");
        generateQrcFile(QString("%1/resources/resources.qrc").arg(projectPath));
    }
    else if (projectType == "Qt Quick Application") {
        dir.mkdir("qml");
        dir.mkdir("assets");
        dir.mkdir("imports");
        generateQmlMainFile(QString("%1/qml/main.qml").arg(projectPath));
        generateQrcFile(QString("%1/resources.qrc").arg(projectPath));
    }
    else if (projectType == "Qt Plugin") {
        dir.mkdir("plugins");
        dir.mkdir("interfaces");
    }
}

void DeepSeekProjectGenerator::generateCMakeProject(const QString &projectPath,
                                                  const QString &projectName,
                                                  const QString &projectType,
                                                  const QString &prompt)
{
    QFile cmakeFile(QString("%1/CMakeLists.txt").arg(projectPath));
    if (!cmakeFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOccurred(tr("Failed to create CMakeLists.txt"));
        return;
    }

    QTextStream out(&cmakeFile);
    out << "# Generated by DeepSeek Plugin on " << QDateTime::currentDateTime().toString() << "\n";
    out << "# Project type: " << projectType << "\n";
    out << "# Prompt: " << prompt << "\n\n";

    out << "cmake_minimum_required(VERSION 3.16)\n\n";
    out << "project(" << projectName << " LANGUAGES CXX)\n\n";
    out << "set(CMAKE_CXX_STANDARD 20)\n";
    out << "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n";
    out << "set(CMAKE_AUTOMOC ON)\n";
    out << "set(CMAKE_AUTORCC ON)\n";
    out << "set(CMAKE_AUTOUIC ON)\n\n";

    if (projectType == "Qt Widgets Application") {
        out << "find_package(Qt6 REQUIRED COMPONENTS Widgets)\n\n";
        out << "qt_add_executable(" << projectName << "\n";
        out << "  src/main.cpp\n";
        out << "  src/mainwindow.cpp\n";
        out << ")\n\n";
        out << "target_link_libraries(" << projectName << " PRIVATE Qt6::Widgets)\n";
        out << "qt_add_resources(" << projectName << " PRIVATE resources.qrc)\n";

        generateMainCpp(QString("%1/src/main.cpp").arg(projectPath), projectType, prompt);
        generateHeader(QString("%1/src/mainwindow.h").arg(projectPath), "MainWindow");
        generateUiFile(QString("%1/forms/mainwindow.ui").arg(projectPath), "MainWindow");
    }
    else if (projectType == "Qt Quick Application") {
        out << "find_package(Qt6 REQUIRED COMPONENTS Quick)\n\n";
        out << "qt_add_executable(" << projectName << "\n";
        out << "  src/main.cpp\n";
        out << ")\n\n";
        out << "target_link_libraries(" << projectName << " PRIVATE Qt6::Quick)\n";
        out << "qt_add_resources(" << projectName << " PRIVATE resources.qrc)\n";

        generateMainCpp(QString("%1/src/main.cpp").arg(projectPath), projectType, prompt);
        generateQmlMainFile(QString("%1/qml/main.qml").arg(projectPath));
    }
    else if (projectType == "Qt Plugin") {
        out << "find_package(Qt6 REQUIRED COMPONENTS Core)\n\n";
        out << "qt_add_plugin(" << projectName << ")\n";
        out << "target_sources(" << projectName << " PRIVATE\n";
        out << "  src/" << projectName.toLower() << "plugin.cpp\n";
        out << "  include/" << projectName.toLower() << "plugin.h\n";
        out << ")\n\n";
        out << "target_link_libraries(" << projectName << " PRIVATE Qt6::Core)\n";

        generatePluginFiles(projectPath, projectName);
    }
    else { // Console Application, Static/Shared Library
        out << "add_" << (projectType.contains("Library") ?
                         (projectType == "Static Library" ? "library(" : "shared_library(") :
                         "executable(") << projectName << "\n";
        out << "  src/main.cpp\n";
        if (projectType != "Console Application") {
            out << "  include/" << projectName.toLower() << ".h\n";
            out << "  src/" << projectName.toLower() << ".cpp\n";
        }
        out << ")\n";

        generateMainCpp(QString("%1/src/main.cpp").arg(projectPath), projectType, prompt);
        if (projectType != "Console Application") {
            generateHeader(QString("%1/include/%2.h").arg(projectPath).arg(projectName.toLower()),
                         projectName);
            generateSource(QString("%1/src/%2.cpp").arg(projectPath).arg(projectName.toLower()),
                         projectName);
        }
    }

    cmakeFile.close();
}

void DeepSeekProjectGenerator::generateQMakeProject(const QString &projectPath,
                                                  const QString &projectName,
                                                  const QString &projectType,
                                                  const QString &prompt)
{
    QFile proFile(QString("%1/%2.pro").arg(projectPath).arg(projectName));
    if (!proFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOccurred(tr("Failed to create .pro file"));
        return;
    }

    QTextStream out(&proFile);
    out << "# Generated by DeepSeek Plugin on " << QDateTime::currentDateTime().toString() << "\n";
    out << "# Project type: " << projectType << "\n";
    out << "# Prompt: " << prompt << "\n\n";

    out << "TEMPLATE = ";
    if (projectType.contains("Application")) {
        out << "app";
    } else if (projectType == "Static Library") {
        out << "lib\nCONFIG += staticlib";
    } else if (projectType == "Shared Library") {
        out << "lib\nCONFIG += shared";
    } else if (projectType == "Qt Plugin") {
        out << "lib\nCONFIG += plugin";
    }
    out << "\n\n";

    out << "TARGET = " << projectName << "\n";
    out << "QT += ";
    if (projectType == "Qt Widgets Application") {
        out << "widgets";
    } else if (projectType == "Qt Quick Application") {
        out << "quick";
    } else if (projectType == "Qt Plugin") {
        out << "core";
    }
    out << "\n\n";

    out << "SOURCES += src/main.cpp\n";
    if (projectType == "Qt Widgets Application") {
        out << "HEADERS += src/mainwindow.h\n";
        out << "FORMS += forms/mainwindow.ui\n";
        out << "RESOURCES += resources/resources.qrc\n";
    } else if (projectType == "Qt Quick Application") {
        out << "RESOURCES += resources.qrc\n";
    } else if (projectType == "Qt Plugin") {
        out << "HEADERS += include/" << projectName.toLower() << "plugin.h\n";
        out << "SOURCES += src/" << projectName.toLower() << "plugin.cpp\n";
    } else if (!projectType.contains("Application")) {
        out << "HEADERS += include/" << projectName.toLower() << ".h\n";
        out << "SOURCES += src/" << projectName.toLower() << ".cpp\n";
    }

    proFile.close();

    // Generar archivos específicos
    if (projectType == "Qt Widgets Application") {
        generateMainCpp(QString("%1/src/main.cpp").arg(projectPath), projectType, prompt);
        generateHeader(QString("%1/src/mainwindow.h").arg(projectPath), "MainWindow");
        generateUiFile(QString("%1/forms/mainwindow.ui").arg(projectPath), "MainWindow");
    } else if (projectType == "Qt Quick Application") {
        generateMainCpp(QString("%1/src/main.cpp").arg(projectPath), projectType, prompt);
        generateQmlMainFile(QString("%1/qml/main.qml").arg(projectPath));
    } else if (projectType == "Qt Plugin") {
        generatePluginFiles(projectPath, projectName);
    } else {
        generateMainCpp(QString("%1/src/main.cpp").arg(projectPath), projectType, prompt);
        if (!projectType.contains("Application")) {
            generateHeader(QString("%1/include/%2.h").arg(projectPath).arg(projectName.toLower()),
                         projectName);
            generateSource(QString("%1/src/%2.cpp").arg(projectPath).arg(projectName.toLower()),
                         projectName);
        }
    }
}

void DeepSeekProjectGenerator::generateQbsProject(const QString &projectPath,
                                                  const QString &projectName,
                                                  const QString &projectType,
                                                  const QString &prompt)
{
    QFile qbsFile(QString("%1/%2.qbs").arg(projectPath).arg(projectName));
    if (!qbsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOccurred(tr("Failed to create QBS project file"));
        return;
    }

    QTextStream out(&qbsFile);
    out << "// Generated by DeepSeek Plugin on " << QDateTime::currentDateTime().toString() << "\n";
    out << "// Project type: " << projectType << "\n";
    out << "// Prompt: " << prompt << "\n\n";

    out << "import qbs\n\n";

    out << "Project {\n";
    out << "    name: \"" << projectName << "\"\n\n";

    out << "    references: [\n";
    out << "        \"src/src.qbs\",\n";
    if (projectType == "Qt Widgets Application" || projectType == "Qt Quick Application") {
        out << "        \"resources/resources.qbs\"\n";
    }
    out << "    ]\n";
    out << "}\n";
    qbsFile.close();

    // Generate src/src.qbs
    QDir().mkpath(projectPath + "/src");
    QFile srcQbsFile(projectPath + "/src/src.qbs");
    if (srcQbsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream srcOut(&srcQbsFile);
        srcOut << "import qbs\n";

        if (projectType == "Qt Widgets Application") {
            srcOut << "import qbs.qt\n\n";
            srcOut << "Application {\n";
            srcOut << "    name: \"" << projectName << "\"\n";
            srcOut << "    type: \"application\"\n";
            srcOut << "    consoleApplication: false\n";
            srcOut << "    qt.core.enableKeywords: true\n";
            srcOut << "    Depends { name: \"Qt\"; submodules: [\"core\", \"widgets\"] }\n\n";
            srcOut << "    files: [\n";
            srcOut << "        \"main.cpp\",\n";
            srcOut << "        \"../resources/resources.qrc\"\n";
            srcOut << "    ]\n";
            srcOut << "}\n";
        }
        else if (projectType == "Qt Quick Application") {
            srcOut << "import qbs.qt\n\n";
            srcOut << "Application {\n";
            srcOut << "    name: \"" << projectName << "\"\n";
            srcOut << "    type: \"application\"\n";
            srcOut << "    consoleApplication: false\n";
            srcOut << "    Depends { name: \"Qt\"; submodules: [\"core\", \"quick\"] }\n\n";
            srcOut << "    files: [\n";
            srcOut << "        \"main.cpp\",\n";
            srcOut << "        \"../qml/main.qml\",\n";
            srcOut << "        \"../resources.qrc\"\n";
            srcOut << "    ]\n";
            srcOut << "}\n";
        }
        else if (projectType == "Static Library") {
            srcOut << "Library {\n";
            srcOut << "    name: \"" << projectName << "\"\n";
            srcOut << "    type: \"staticlibrary\"\n";
            srcOut << "    files: [\n";
            srcOut << "        \"" << projectName.toLower() << ".cpp\",\n";
            srcOut << "        \"" << projectName.toLower() << ".h\"\n";
            srcOut << "    ]\n";
            srcOut << "}\n";
        }
        else if (projectType == "Shared Library") {
            srcOut << "Library {\n";
            srcOut << "    name: \"" << projectName << "\"\n";
            srcOut << "    type: \"dynamiclibrary\"\n";
            srcOut << "    files: [\n";
            srcOut << "        \"" << projectName.toLower() << ".cpp\",\n";
            srcOut << "        \"" << projectName.toLower() << ".h\"\n";
            srcOut << "    ]\n";
            srcOut << "}\n";
        }
        srcQbsFile.close();
    }

    // Generate resources.qbs if needed
    if (projectType == "Qt Widgets Application") {
        QDir().mkpath(projectPath + "/resources");
        QFile resQbsFile(projectPath + "/resources/resources.qbs");
        if (resQbsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream resOut(&resQbsFile);
            resOut << "import qbs\n\n";
            resOut << "QtResource {\n";
            resOut << "    name: \"" << projectName << "-resources\"\n";
            resOut << "    files: [\"resources.qrc\"]\n";
            resOut << "}\n";
            resQbsFile.close();
        }
    }

    // Generate main source files
    if (projectType.contains("Application")) {
        generateMainCpp(QString("%1/src/main.cpp").arg(projectPath), projectType, prompt);
        if (projectType == "Qt Widgets Application") {
            generateUiFile(QString("%1/forms/mainwindow.ui").arg(projectPath), "MainWindow");
            generateQrcFile(QString("%1/resources/resources.qrc").arg(projectPath));
        } else if (projectType == "Qt Quick Application") {
            generateQmlMainFile(QString("%1/qml/main.qml").arg(projectPath));
            generateQrcFile(QString("%1/resources.qrc").arg(projectPath));
        }
    } else {
        QString className = projectName;
        if (!className.isEmpty()) {
            className[0] = className[0].toUpper();
        }
        generateMainCpp(QString("%1/src/%2.cpp").arg(projectPath).arg(projectName.toLower()),
                        projectType, prompt);
        generateHeader(QString("%1/include/%2.h").arg(projectPath).arg(projectName.toLower()),
                       className);
    }
}

void DeepSeekProjectGenerator::generateMainCpp(const QString &filePath,
                                             const QString &projectType,
                                             const QString &prompt)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOccurred(tr("Failed to create main source file: %1").arg(filePath));
        return;
    }

    QTextStream out(&file);
    out << "// Generated by DeepSeek Plugin\n";
    out << "// Project type: " << projectType << "\n";
    out << "// Prompt: " << prompt << "\n\n";

    if (projectType == "Qt Widgets Application") {
        out << "#include <QApplication>\n";
        out << "#include \"mainwindow.h\"\n\n";
        out << "int main(int argc, char *argv[])\n";
        out << "{\n";
        out << "    QApplication app(argc, argv);\n\n";
        out << "    MainWindow window;\n";
        out << "    window.show();\n\n";
        out << "    return app.exec();\n";
        out << "}\n";
    }
    else if (projectType == "Qt Quick Application") {
        out << "#include <QGuiApplication>\n";
        out << "#include <QQmlApplicationEngine>\n\n";
        out << "int main(int argc, char *argv[])\n";
        out << "{\n";
        out << "    QGuiApplication app(argc, argv);\n\n";
        out << "    QQmlApplicationEngine engine;\n";
        out << "    engine.load(QUrl(QStringLiteral(\"qrc:/main.qml\")));\n\n";
        out << "    return app.exec();\n";
        out << "}\n";
    }
    else if (projectType == "Console Application") {
        out << "#include <iostream>\n\n";
        out << "int main()\n";
        out << "{\n";
        out << "    std::cout << \"Hello, world!\\n\";\n";
        out << "    return 0;\n";
        out << "}\n";
    }
    else if (projectType == "Qt Plugin") {
        out << "#include \"" << QFileInfo(filePath).baseName() << "plugin.h\"\n\n";
        out << "#include <QtCore>\n\n";
        out << "Q_EXPORT_PLUGIN2(" << QFileInfo(filePath).baseName() << ", "
           << QFileInfo(filePath).baseName() << "Plugin)\n";
    }

    file.close();
}

void DeepSeekProjectGenerator::generateHeader(const QString &filePath,
                                            const QString &className)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOccurred(tr("Failed to create header file: %1").arg(filePath));
        return;
    }

    QString guard = QString("%1_%2_H").arg(className.toUpper()).arg(className.toUpper());

    QTextStream out(&file);
    out << "// Generated by DeepSeek Plugin\n\n";
    out << "#ifndef " << guard << "\n";
    out << "#define " << guard << "\n\n";

    if (filePath.contains("mainwindow")) {
        out << "#include <QMainWindow>\n\n";
        out << "class " << className << " : public QMainWindow\n";
    } else if (filePath.contains("plugin")) {
        out << "#include <QObject>\n";
        out << "#include <QtPlugin>\n\n";
        out << "class " << className << " : public QObject\n";
    } else {
        out << "class " << className << "\n";
    }

    out << "{\n";
    out << "    Q_OBJECT\n";
    if (filePath.contains("plugin")) {
        out << "    Q_PLUGIN_METADATA(IID \"org.qt-project.Qt." << className << "\" FILE \"metadata.json\")\n";
    }
    out << "public:\n";
    out << "    " << className << "();\n";
    if (filePath.contains("mainwindow")) {
        out << "    ~" << className << "();\n\n";
        out << "private slots:\n";
        out << "    void initUI();\n";
    }
    out << "};\n\n";
    out << "#endif // " << guard << "\n";

    file.close();
}

void DeepSeekProjectGenerator::generateSource(const QString &filePath,
                                            const QString &className)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOccurred(tr("Failed to create source file: %1").arg(filePath));
        return;
    }

    QTextStream out(&file);
    out << "// Generated by DeepSeek Plugin\n\n";
    out << "#include \"" << className.toLower() << ".h\"\n\n";
    out << className << "::" << className << "()\n";
    out << "{\n";
    if (filePath.contains("mainwindow")) {
        out << "    initUI();\n";
    }
    out << "}\n";

    if (filePath.contains("mainwindow")) {
        out << "\n" << className << "::~" << className << "()\n";
        out << "{\n";
        out << "}\n\n";
        out << "void " << className << "::initUI()\n";
        out << "{\n";
        out << "    // Initialize user interface\n";
        out << "}\n";
    }

    file.close();
}

void DeepSeekProjectGenerator::generatePluginFiles(const QString &projectPath,
                                                 const QString &pluginName)
{
    QString className = pluginName;
    if (!className.isEmpty()) {
        className[0] = className[0].toUpper();
    }

    // Generar archivo de metadatos
    QFile metadataFile(QString("%1/metadata.json").arg(projectPath));
    if (metadataFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&metadataFile);
        out << "{\n";
        out << "    \"Keys\" : [\"" << pluginName << "\"]\n";
        out << "}\n";
        metadataFile.close();
    }

    // Generar archivos principales del plugin
    generateHeader(QString("%1/include/%2plugin.h").arg(projectPath).arg(pluginName.toLower()),
                 className + "Plugin");
    generateSource(QString("%1/src/%2plugin.cpp").arg(projectPath).arg(pluginName.toLower()),
                 className + "Plugin");
}

void DeepSeekProjectGenerator::generateQmlMainFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOccurred(tr("Failed to create QML file: %1").arg(filePath));
        return;
    }

    QTextStream out(&file);
    out << "import QtQuick 2.15\n";
    out << "import QtQuick.Controls 2.15\n\n";
    out << "ApplicationWindow {\n";
    out << "    visible: true\n";
    out << "    width: 640\n";
    out << "    height: 480\n";
    out << "    title: qsTr(\"DeepSeek Generated App\")\n\n";
    out << "    Rectangle {\n";
    out << "        anchors.fill: parent\n";
    out << "        color: \"lightblue\"\n\n";
    out << "        Text {\n";
    out << "            anchors.centerIn: parent\n";
    out << "            text: qsTr(\"Hello from DeepSeek!\")\n";
    out << "            font.pixelSize: 24\n";
    out << "        }\n";
    out << "    }\n";
    out << "}\n";

    file.close();
}

void DeepSeekProjectGenerator::generateUiFile(const QString &filePath,
                                            const QString &formClass)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOccurred(tr("Failed to create UI file: %1").arg(filePath));
        return;
    }

    QTextStream out(&file);
    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    out << "<ui version=\"4.0\">\n";
    out << " <class>" << formClass << "</class>\n";
    out << " <widget class=\"QMainWindow\" name=\"" << formClass << "\">\n";
    out << "  <property name=\"geometry\">\n";
    out << "   <rect>\n";
    out << "    <x>0</x>\n";
    out << "    <y>0</y>\n";
    out << "    <width>600</width>\n";
    out << "    <height>400</height>\n";
    out << "   </rect>\n";
    out << "  </property>\n";
    out << "  <property name=\"windowTitle\">\n";
    out << "   <string>" << formClass << "</string>\n";
    out << "  </property>\n";
    out << "  <widget class=\"QWidget\" name=\"centralwidget\">\n";
    out << "   <widget class=\"QLabel\" name=\"label\">\n";
    out << "    <property name=\"geometry\">\n";
    out << "     <rect>\n";
    out << "      <x>190</x>\n";
    out << "      <y>160</y>\n";
    out << "      <width>221</width>\n";
    out << "      <height>41</height>\n";
    out << "     </rect>\n";
    out << "    </property>\n";
    out << "    <property name=\"text\">\n";
    out << "     <string>Hello from DeepSeek!</string>\n";
    out << "    </property>\n";
    out << "   </widget>\n";
    out << "  </widget>\n";
    out << "  <widget class=\"QMenuBar\" name=\"menubar\">\n";
    out << "   <property name=\"geometry\">\n";
    out << "    <rect>\n";
    out << "     <x>0</x>\n";
    out << "     <y>0</y>\n";
    out << "     <width>600</width>\n";
    out << "     <height>22</height>\n";
    out << "     </rect>\n";
    out << "   </property>\n";
    out << "  </widget>\n";
    out << "  <widget class=\"QStatusBar\" name=\"statusbar\"/>\n";
    out << " </widget>\n";
    out << " <resources/>\n";
    out << " <connections/>\n";
    out << "</ui>\n";

    file.close();
}

void DeepSeekProjectGenerator::generateQrcFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOccurred(tr("Failed to create resource file: %1").arg(filePath));
        return;
    }

    QTextStream out(&file);
    out << "<RCC>\n";
    out << "    <qresource prefix=\"/\">\n";
    if (filePath.contains("resources.qrc")) {
        out << "        <file>forms/mainwindow.ui</file>\n";
        out << "        <file>images/logo.png</file>\n";
    } else {
        out << "        <file>qml/main.qml</file>\n";
    }
    out << "    </qresource>\n";
    out << "</RCC>\n";

    file.close();
}

} // namespace Internal
} // namespace DeepSeekAI
