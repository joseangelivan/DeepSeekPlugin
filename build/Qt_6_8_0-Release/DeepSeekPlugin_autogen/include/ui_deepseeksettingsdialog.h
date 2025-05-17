/********************************************************************************
** Form generated from reading UI file 'deepseeksettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEEPSEEKSETTINGSDIALOG_H
#define UI_DEEPSEEKSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DeepSeekSettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *apiKeyLineEdit;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DeepSeekSettingsDialog)
    {
        if (DeepSeekSettingsDialog->objectName().isEmpty())
            DeepSeekSettingsDialog->setObjectName("DeepSeekSettingsDialog");
        DeepSeekSettingsDialog->resize(400, 200);
        verticalLayout = new QVBoxLayout(DeepSeekSettingsDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(DeepSeekSettingsDialog);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        apiKeyLineEdit = new QLineEdit(groupBox);
        apiKeyLineEdit->setObjectName("apiKeyLineEdit");
        apiKeyLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(apiKeyLineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(DeepSeekSettingsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DeepSeekSettingsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DeepSeekSettingsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DeepSeekSettingsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DeepSeekSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *DeepSeekSettingsDialog)
    {
        DeepSeekSettingsDialog->setWindowTitle(QCoreApplication::translate("DeepSeekSettingsDialog", "DeepSeek API Settings", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DeepSeekSettingsDialog", "API Configuration", nullptr));
        label->setText(QCoreApplication::translate("DeepSeekSettingsDialog", "DeepSeek API Key:", nullptr));
        label_2->setText(QCoreApplication::translate("DeepSeekSettingsDialog", "Get your API key from DeepSeek platform", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeepSeekSettingsDialog: public Ui_DeepSeekSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEEPSEEKSETTINGSDIALOG_H
