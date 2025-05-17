#pragma once

#include <QObject>
#include <QMap>
#include <QtConcurrent/QtConcurrent>
#include <projectexplorer/project.h>
#include <projectexplorer/projectnodes.h>
#include <utils/filepath.h>

namespace ProjectExplorer {
class Project;
class ProjectNode;
class FileNode;
}

namespace DeepSeekAI {
namespace Internal {

class DeepSeekProjectGenerator : public QObject
{
    Q_OBJECT
public:
    enum BuildSystem {
        CMake,
        QMake,
        Qbs
    };
    Q_ENUM(BuildSystem)

    explicit DeepSeekProjectGenerator(QObject *parent = nullptr);
    ~DeepSeekProjectGenerator();

    void initialize();
    void generateProject(const QString &projectName,
                         const QString &projectPath,
                         BuildSystem buildSystem,
                         const QString &projectType,
                         const QString &prompt);

    void openAndAnalyzeProject(const QString &projectFilePath);
    void optimizeProjectStructure(const QMap<QString, QString> &projectContents);

    static QStringList availableProjectTypes();
    static QStringList availableBuildSystems();

signals:
    void projectGenerated(const QString &projectPath);
    void projectOpened(ProjectExplorer::Project* project);
    void projectAnalysisComplete(const QMap<QString, QString>& fileContents);
    void optimizationComplete(const QMap<QString, QString>& optimizedFiles);
    void errorOccurred(const QString &error);

private:
    void createProjectStructure(const QString &projectPath, const QString &projectType);
    void generateCMakeProject(const QString &projectPath, const QString &projectName,
                              const QString &projectType, const QString &prompt);
    void generateQMakeProject(const QString &projectPath, const QString &projectName,
                              const QString &projectType, const QString &prompt);
    void generateQbsProject(const QString &projectPath, const QString &projectName,
                            const QString &projectType, const QString &prompt);
    void generateMainCpp(const QString &filePath, const QString &projectType, const QString &prompt);
    void generateHeader(const QString &filePath, const QString &className);
    void generateSource(const QString &filePath, const QString &className);
    void generateQmlMainFile(const QString &filePath);
    void generateUiFile(const QString &filePath, const QString &formClass);
    void generateQrcFile(const QString &filePath);
    void generatePluginFiles(const QString &projectPath, const QString &pluginName);
    void analyzeProjectNode(ProjectExplorer::ProjectNode *node, QMap<QString, QString> &contents);
};

} // namespace Internal
} // namespace DeepSeekAI
