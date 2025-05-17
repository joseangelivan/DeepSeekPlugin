#include "deepseekcodeeditor.h"

#include <coreplugin/editormanager/editormanager.h>
#include <texteditor/texteditor.h>
#include <texteditor/textdocument.h>
#include <utils/fileutils.h>
#include <QTextCursor>

using namespace Core;
using namespace TextEditor;
using namespace Utils;

namespace DeepSeekAI {
namespace Internal {

DeepSeekCodeEditor::DeepSeekCodeEditor(QObject *parent)
    : QObject(parent)
{
    connect(EditorManager::instance(), &EditorManager::currentEditorChanged,
            this, &DeepSeekCodeEditor::onEditorChanged);

    connect(EditorManager::instance(), &EditorManager::currentEditorChanged,
            this, &DeepSeekCodeEditor::onEditorChanged);

    if (auto editor = EditorManager::currentEditor()) {
        onEditorChanged(editor);
    }
}

DeepSeekCodeEditor::~DeepSeekCodeEditor()
{
    disconnect(EditorManager::instance(), &EditorManager::currentEditorChanged,
               this, &DeepSeekCodeEditor::onEditorChanged);
}

bool DeepSeekCodeEditor::hasActiveEditor() const
{
    return m_currentEditor != nullptr && m_currentDocument != nullptr;
}

QString DeepSeekCodeEditor::currentFileContent() const
{
    return hasActiveEditor() ? m_currentDocument->plainText() : QString();
}

QString DeepSeekCodeEditor::currentFileName() const
{
    return hasActiveEditor() ? m_currentDocument->filePath().fileName() : QString();
}

QString DeepSeekCodeEditor::currentFilePath() const
{
    // return hasActiveEditor() ? m_currentDocument->filePath().toString() : QString();
    return hasActiveEditor() ? m_currentDocument->filePath().toUserOutput() : QString();
}

void DeepSeekCodeEditor::replaceCurrentFileContent(const QString &newContent)
{
    if (!hasActiveEditor()) {
        return;
    }

    QTextCursor cursor(m_currentDocument->document());
    cursor.select(QTextCursor::Document);
    cursor.insertText(newContent);

    emit contentChanged();
}

void DeepSeekCodeEditor::insertCodeAtCursor(const QString &code)
{
    if (!hasActiveEditor()) {
        return;
    }

    m_currentEditor->editorWidget()->insertPlainText(code);
    emit contentChanged();
}

void DeepSeekCodeEditor::insertCodeAtPosition(const QString &code, int line, int column)
{
    if (!hasActiveEditor()) {
        return;
    }

    QTextCursor cursor(m_currentDocument->document());
    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, line - 1);
    cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, column);
    cursor.insertText(code);

    emit contentChanged();
}

void DeepSeekCodeEditor::saveCurrentFile()
{
    if (!hasActiveEditor()) {
        return;
    }

    if (m_currentDocument->save()) {
        emit fileSaved(m_currentDocument->filePath().toUserOutput());
    }
}

void DeepSeekCodeEditor::onEditorChanged(Core::IEditor *editor)
{
    if (m_currentEditor) {
        disconnect(m_currentDocument, &TextDocument::contentsChanged,
                  this, &DeepSeekCodeEditor::contentChanged);
    }

    m_currentEditor = qobject_cast<BaseTextEditor*>(editor);
    m_currentDocument = m_currentEditor ? m_currentEditor->textDocument() : nullptr;

    if (m_currentDocument) {
        connect(m_currentDocument, &TextDocument::contentsChanged,
                this, &DeepSeekCodeEditor::contentChanged);
    }

    emit editorChanged();
}

} // namespace Internal
} // namespace DeepSeekAI
