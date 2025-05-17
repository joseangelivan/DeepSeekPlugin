#ifndef DEEPSEEKCODEEDITOR_H
#define DEEPSEEKCODEEDITOR_H

#include <QObject>
#include <texteditor/texteditor.h>

namespace TextEditor {
class BaseTextEditor;
class TextDocument;
}

namespace Core {
class IEditor;
}

namespace DeepSeekAI {
namespace Internal {

class DeepSeekCodeEditor : public QObject
{
    Q_OBJECT

public:
    explicit DeepSeekCodeEditor(QObject *parent = nullptr);
    ~DeepSeekCodeEditor();

    bool hasActiveEditor() const;
    QString currentFileContent() const;
    QString currentFileName() const;
    QString currentFilePath() const;
    void replaceCurrentFileContent(const QString &newContent);
    void insertCodeAtCursor(const QString &code);
    void insertCodeAtPosition(const QString &code, int line, int column);
    void saveCurrentFile();

public slots:
    void onEditorChanged(Core::IEditor *editor);

signals:
    void editorChanged();
    void contentChanged();
    void fileSaved(const QString &filePath);

private:
    TextEditor::BaseTextEditor *m_currentEditor = nullptr;
    TextEditor::TextDocument *m_currentDocument = nullptr;
};

} // namespace Internal
} // namespace DeepSeekAI

#endif // DEEPSEEKCODEEDITOR_H
