/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QGridLayout *gridLayout;
    QTextEdit *newsTextEdit;
    QLabel *label_7;
    QLabel *otherportlabel;
    QLabel *label_3;
    QPushButton *sendButton;
    QLabel *label_2;
    QLabel *otheriplabel;
    QLabel *label_5;
    QLabel *label_4;
    QTextBrowser *newstextBrowser;
    QPushButton *closeButton;
    QPushButton *pushButton;
    QLabel *myportlabel;

    void setupUi(QDialog *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QStringLiteral("ChatDialog"));
        ChatDialog->resize(560, 478);
        gridLayout = new QGridLayout(ChatDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        newsTextEdit = new QTextEdit(ChatDialog);
        newsTextEdit->setObjectName(QStringLiteral("newsTextEdit"));

        gridLayout->addWidget(newsTextEdit, 3, 0, 1, 6);

        label_7 = new QLabel(ChatDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        otherportlabel = new QLabel(ChatDialog);
        otherportlabel->setObjectName(QStringLiteral("otherportlabel"));

        gridLayout->addWidget(otherportlabel, 0, 6, 1, 2);

        label_3 = new QLabel(ChatDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        sendButton = new QPushButton(ChatDialog);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        gridLayout->addWidget(sendButton, 4, 4, 1, 2);

        label_2 = new QLabel(ChatDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 6, 3, 2);

        otheriplabel = new QLabel(ChatDialog);
        otheriplabel->setObjectName(QStringLiteral("otheriplabel"));

        gridLayout->addWidget(otheriplabel, 0, 1, 1, 1);

        label_5 = new QLabel(ChatDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 5, 1, 1);

        label_4 = new QLabel(ChatDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 4, 1, 1);

        newstextBrowser = new QTextBrowser(ChatDialog);
        newstextBrowser->setObjectName(QStringLiteral("newstextBrowser"));

        gridLayout->addWidget(newstextBrowser, 1, 0, 1, 6);

        closeButton = new QPushButton(ChatDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        gridLayout->addWidget(closeButton, 4, 0, 1, 2);

        pushButton = new QPushButton(ChatDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 3, 1, 3);

        myportlabel = new QLabel(ChatDialog);
        myportlabel->setObjectName(QStringLiteral("myportlabel"));

        gridLayout->addWidget(myportlabel, 0, 3, 1, 1);


        retranslateUi(ChatDialog);

        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QDialog *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "Dialog", Q_NULLPTR));
        label_7->setText(QApplication::translate("ChatDialog", "\346\234\254\345\234\260\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        otherportlabel->setText(QString());
        label_3->setText(QApplication::translate("ChatDialog", "\345\257\271\346\226\271IP:", Q_NULLPTR));
        sendButton->setText(QApplication::translate("ChatDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChatDialog", "TextLabel", Q_NULLPTR));
        otheriplabel->setText(QString());
        label_5->setText(QApplication::translate("ChatDialog", "\350\246\201\350\277\236\346\216\245\347\232\204\347\253\257\345\217\243", Q_NULLPTR));
        label_4->setText(QApplication::translate("ChatDialog", "\342\200\224>", Q_NULLPTR));
        closeButton->setText(QApplication::translate("ChatDialog", "\345\205\263\351\227\255", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ChatDialog", "\344\277\235\345\255\230\346\266\210\346\201\257\350\256\260\345\275\225", Q_NULLPTR));
        myportlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
