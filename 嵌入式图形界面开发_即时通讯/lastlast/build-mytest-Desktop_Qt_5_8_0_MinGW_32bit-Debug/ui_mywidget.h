/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_5;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QWidget *page_2;
    QWidget *page_3;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QStringLiteral("MyWidget"));
        MyWidget->resize(205, 405);
        gridLayout = new QGridLayout(MyWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolBox = new QToolBox(MyWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 187, 309));
        verticalLayoutWidget = new QWidget(page);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 191, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_5 = new QToolButton(verticalLayoutWidget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));

        verticalLayout->addWidget(toolButton_5);

        toolButton_4 = new QToolButton(verticalLayoutWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));

        verticalLayout->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(verticalLayoutWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));

        verticalLayout->addWidget(toolButton_3);

        toolButton_2 = new QToolButton(verticalLayoutWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));

        verticalLayout->addWidget(toolButton_2);

        toolButton = new QToolButton(verticalLayoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        verticalLayout->addWidget(toolButton);

        toolBox->addItem(page, QString::fromUtf8("\346\210\221\347\232\204\345\245\275\345\217\213"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 187, 309));
        toolBox->addItem(page_2, QString::fromUtf8("\351\231\214\347\224\237\344\272\272"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 187, 309));
        toolBox->addItem(page_3, QString::fromUtf8("\351\273\221\345\220\215\345\215\225"));

        gridLayout->addWidget(toolBox, 0, 0, 1, 1);


        retranslateUi(MyWidget);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", Q_NULLPTR));
        toolButton_5->setText(QApplication::translate("MyWidget", "...", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("MyWidget", "...", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("MyWidget", "...", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("MyWidget", "...", Q_NULLPTR));
        toolButton->setText(QApplication::translate("MyWidget", "...", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MyWidget", "\346\210\221\347\232\204\345\245\275\345\217\213", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MyWidget", "\351\231\214\347\224\237\344\272\272", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("MyWidget", "\351\273\221\345\220\215\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
