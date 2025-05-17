#include "deepseeksettingsdialog.h"
#include "ui_deepseeksettingsdialog.h"

#include <QSettings>
#include <QMessageBox>
#include <QPushButton>

namespace DeepSeekAI {
namespace Internal {

DeepSeekSettingsDialog::DeepSeekSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeepSeekSettingsDialog)
{
    ui->setupUi(this);

    // Configurar el diálogo
    setWindowTitle(tr("DeepSeek API Settings"));
    setModal(true);

    // Cargar la API Key existente
    ui->apiKeyLineEdit->setText(loadApiKey());

    // Conectar señales
    connect(ui->apiKeyLineEdit, &QLineEdit::textChanged,
            this, &DeepSeekSettingsDialog::onApiKeyChanged);

    // Configurar botones
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

DeepSeekSettingsDialog::~DeepSeekSettingsDialog()
{
    delete ui;
}

QString DeepSeekSettingsDialog::apiKey() const
{
    return ui->apiKeyLineEdit->text().trimmed();
}

void DeepSeekSettingsDialog::setApiKey(const QString &key)
{
    ui->apiKeyLineEdit->setText(key);
}

void DeepSeekSettingsDialog::onApiKeyChanged()
{
    bool valid = !apiKey().isEmpty();
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(valid);
}

QString DeepSeekSettingsDialog::loadApiKey()
{
    QSettings settings;
    settings.beginGroup("DeepSeekPlugin");
    QString key = settings.value("ApiKey").toString();
    settings.endGroup();

    return key;
}

void DeepSeekSettingsDialog::saveApiKey(const QString &key)
{
    QSettings settings;
    settings.beginGroup("DeepSeekPlugin");
    settings.setValue("ApiKey", key.trimmed());
    settings.endGroup();
}

} // namespace Internal
} // namespace DeepSeekAI
