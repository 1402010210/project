/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *regButton;
    QPushButton *pushButton_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_4;
    QLineEdit *lineEdit;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QStringLiteral("MyDialog"));
        MyDialog->resize(400, 313);
        label = new QLabel(MyDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 400, 180));
        label_2 = new QLabel(MyDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 190, 54, 12));
        lineEdit_2 = new QLineEdit(MyDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(132, 220, 141, 20));
        lineEdit_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_2->setToolTipDuration(0);
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(MyDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 220, 54, 12));
        pushButton = new QPushButton(MyDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 270, 181, 31));
        regButton = new QPushButton(MyDialog);
        regButton->setObjectName(QStringLiteral("regButton"));
        regButton->setGeometry(QRect(290, 190, 75, 23));
        pushButton_3 = new QPushButton(MyDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 220, 75, 23));
        checkBox = new QCheckBox(MyDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(120, 250, 71, 16));
        checkBox_2 = new QCheckBox(MyDialog);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(200, 250, 71, 16));
        label_4 = new QLabel(MyDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(5, 190, 80, 72));
        lineEdit = new QLineEdit(MyDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 189, 141, 21));

        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("MyDialog", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("MyDialog", "\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("MyDialog", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MyDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        regButton->setText(QApplication::translate("MyDialog", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MyDialog", "\351\200\200\345\207\272", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MyDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MyDialog", "\350\207\252\345\212\250\347\231\273\345\275\225", Q_NULLPTR));
        label_4->setText(QApplication::translate("MyDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
