#include "setdialog.h"
#include "ui_setdialog.h"
#include "chatdialog.h"
QString otherport;
QString otherip;
QString myport;
SetDialog::SetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("设置Ip和Port界面"));
    this->setStyleSheet("background-image:url(:/myImage/image/chatback.jpg)");
}

SetDialog::~SetDialog()
{
    delete ui;
}

void SetDialog::on_YESButton_clicked()
{
    //从行编辑器输入自己的端口号、对方IP、要连接到哪个端口号
    myport=ui->MPortLineEdit->text();
    otherip= ui->TIPLineEdit->text();
    otherport= ui->TPortLineEdit->text();
    ChatDialog *chat=new ChatDialog();
    chat->show();
    this->close();
}

void SetDialog::on_backButton_clicked()
{
    this->close();
}
