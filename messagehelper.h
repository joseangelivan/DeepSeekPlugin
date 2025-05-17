#pragma once
#ifndef MESSAGEHELPER_H
#define MESSAGEHELPER_H
#include <coreplugin/messagemanager.h>

// Elimina esta línea conflictiva:
// namespace Core { class MessageManager; }  // ← ESTO CAUSA EL ERROR

namespace DeepSeekAI {
namespace Utils {

class MessageHelper {
public:
    enum MessageType { Silent, Flash, Disrupt };

    static void showMessage(const QString &msg, MessageType type = Flash) {
        switch(type) {
        case Silent:
            Core::MessageManager::writeSilently(format(msg, type));
            break;
        case Flash:
            Core::MessageManager::writeFlashing(format(msg, type));
            break;
        case Disrupt:
            Core::MessageManager::writeDisrupting(format(msg, type));
            break;
        }
    }

private:
    static QString format(const QString &msg, MessageType type) {
        QString prefix;
        QString style;

        switch(type) {
        case Silent:
            style = "color:gray;";
            break;
        case Flash:
            style = "color:blue;";
            prefix = "ℹ️ ";
            break;
        case Disrupt:
            style = "color:red; font-weight:bold;";
            prefix = "❌ ";
            break;
        }

        return QString("<span style='%1'>%2%3</span>")
            .arg(style, prefix, msg);
    }
};

} // namespace Utils
} // namespace DeepSeekAI
#endif // MESSAGEHELPER_H
