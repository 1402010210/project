#include "mywidget.h"
#include "ui_mywidget.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QWidget>
#include <setdialog.h>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    setWindowTitle(tr("My QQ"));
       //我的好友列表
       //设置背景
       this->setStyleSheet("background-image:url(:/myImage/image/chatback.jpg)");
       ui->toolButton->setText(tr("大周"));
       ui->toolButton->setIcon(QPixmap(":/myImage/image/qq.jpg"));
       ui->toolButton->setIconSize(QPixmap(":/myImage/image/qq.jpg").size());
       ui->toolButton->setAutoRaise(true);
       ui->toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

       ui->toolButton_2->setText(tr("小黑"));
       ui->toolButton_2->setIcon(QPixmap(":/myImage/image/qq.jpg"));
       ui->toolButton_2->setIconSize(QPixmap(":/myImage/image/qq.jpg").size());
       ui->toolButton_2->setAutoRaise(true);
       ui->toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

       ui->toolButton_3->setText(tr("大黑"));
       ui->toolButton_3->setIcon(QPixmap(":/myImage/image/qq.jpg"));
       ui->toolButton_3->setIconSize(QPixmap(":/myImage/image/qq.jpg").size());
       ui->toolButton_3->setAutoRaise(true);
       ui->toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

       ui->toolButton_4->setText(tr("小黄"));
       ui->toolButton_4->setIcon(QPixmap(":/myImage/image/qq.jpg"));
       ui->toolButton_4->setIconSize(QPixmap(":/myImage/image/qq.jpg").size());
       ui->toolButton_4->setAutoRaise(true);
       ui->toolButton_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

       ui->toolButton_5->setText(tr("大黄"));
       ui->toolButton_5->setIcon(QPixmap(":/myImage/image/qq.jpg"));
       ui->toolButton_5->setIconSize(QPixmap(":/myImage/image/qq.jpg").size());
       ui->toolButton_5->setAutoRaise(true);
       ui->toolButton_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_toolButton_5_clicked()
{
    SetDialog *set = new SetDialog( );
    set->show();
}

void MyWidget::on_toolButton_4_clicked()
{
    SetDialog *set = new SetDialog( );
    set->show();
}

void MyWidget::on_toolButton_3_clicked()
{
    SetDialog *set = new SetDialog( );
    set->show();
}

void MyWidget::on_toolButton_2_clicked()
{
    SetDialog *set = new SetDialog( );
    set->show();
}

void MyWidget::on_toolButton_clicked()
{
    SetDialog *set = new SetDialog( );
    set->show();
}
