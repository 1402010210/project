/********************************************************************************
** Form generated from reading UI file 'setdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDIALOG_H
#define UI_SETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *YESButton;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *MPortLineEdit;
    QLabel *iPLabel;
    QLineEdit *TIPLineEdit;
    QLabel *Label_2;
    QLineEdit *TPortLineEdit;
    QLabel *label;
    QPushButton *backButton;

    void setupUi(QDialog *SetDialog)
    {
        if (SetDialog->objectName().isEmpty())
            SetDialog->setObjectName(QStringLiteral("SetDialog"));
        SetDialog->resize(370, 300);
        gridLayout = new QGridLayout(SetDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        YESButton = new QPushButton(SetDialog);
        YESButton->setObjectName(QStringLiteral("YESButton"));

        gridLayout->addWidget(YESButton, 2, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        Label = new QLabel(SetDialog);
        Label->setObjectName(QStringLiteral("Label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Label);

        MPortLineEdit = new QLineEdit(SetDialog);
        MPortLineEdit->setObjectName(QStringLiteral("MPortLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, MPortLineEdit);

        iPLabel = new QLabel(SetDialog);
        iPLabel->setObjectName(QStringLiteral("iPLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, iPLabel);

        TIPLineEdit = new QLineEdit(SetDialog);
        TIPLineEdit->setObjectName(QStringLiteral("TIPLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, TIPLineEdit);

        Label_2 = new QLabel(SetDialog);
        Label_2->setObjectName(QStringLiteral("Label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Label_2);

        TPortLineEdit = new QLineEdit(SetDialog);
        TPortLineEdit->setObjectName(QStringLiteral("TPortLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, TPortLineEdit);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        label = new QLabel(SetDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        backButton = new QPushButton(SetDialog);
        backButton->setObjectName(QStringLiteral("backButton"));

        gridLayout->addWidget(backButton, 2, 0, 1, 1);


        retranslateUi(SetDialog);

        QMetaObject::connectSlotsByName(SetDialog);
    } // setupUi

    void retranslateUi(QDialog *SetDialog)
    {
        SetDialog->setWindowTitle(QApplication::translate("SetDialog", "Dialog", Q_NULLPTR));
        YESButton->setText(QApplication::translate("SetDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        Label->setText(QApplication::translate("SetDialog", "\347\253\257\345\217\243\345\217\267:", Q_NULLPTR));
        iPLabel->setText(QApplication::translate("SetDialog", "\350\277\236\346\216\245\347\232\204IP\345\234\260\345\235\200\344\270\272:", Q_NULLPTR));
        Label_2->setText(QApplication::translate("SetDialog", "\350\246\201\350\277\236\346\216\245\347\232\204\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        label->setText(QApplication::translate("SetDialog", "\350\256\276\347\275\256IP\345\234\260\345\235\200\345\222\214\347\233\270\345\272\224\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        backButton->setText(QApplication::translate("SetDialog", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetDialog: public Ui_SetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDIALOG_H
