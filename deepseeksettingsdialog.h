#pragma once

#include <QDialog>

namespace Ui {
class DeepSeekSettingsDialog;
}

namespace DeepSeekAI {
namespace Internal {

class DeepSeekSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeepSeekSettingsDialog(QWidget *parent = nullptr);
    ~DeepSeekSettingsDialog();

    QString apiKey() const;
    void setApiKey(const QString &key);

    static QString loadApiKey();
    static void saveApiKey(const QString &key);

private slots:
    void onApiKeyChanged();

private:
    Ui::DeepSeekSettingsDialog *ui;
};

} // namespace Internal
} // namespace DeepSeekAI
