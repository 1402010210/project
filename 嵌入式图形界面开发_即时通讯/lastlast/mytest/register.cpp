#include "register.h"
#include "ui_register.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
   this->setStyleSheet("background-image:url(:/myImage/image/chatback.jpg)");
}

Register::~Register()
{
    delete ui;
}

void Register::on_YesButton_2_clicked()
{
       QSqlQuery query;
       QString inputpasswd1 = ui->LineEdit_2->text();
       QString inputpasswd2= ui->LineEdit_3->text();
       QString inputname=ui->LineEdit->text();
       if(inputname==""||inputpasswd1==""||inputpasswd2=="")
       {
        qDebug()<<"注册的账户名、密码不可以为空！";
       }
       else if(inputpasswd1!=inputpasswd2)
       {
           qDebug()<<"密码不一致！";
       }
       else
           passwordflag=true;
  //查询先前有无该账户
    query.exec("select name from qquserdata");
    while(1)
    {
        if(query.next())
        {
            QString name =query.value("name").toString();
            qDebug()<<QString("账户名:'%1'").arg(name);
            if(inputname==name)
            {
                qDebug()<<"输入的账户名已经注册过了";
                ui->LineEdit->clear();
                nameflag=false;
                break;
            }
            else
            {
                nameflag=true;
            }

        }
        else
        {
            nameflag=true;//最开始并没有账户信息，可以直接注册
            break;
        }
    }
    //只有当nameflag和passwordflag同时为true,才会插入账户、密码到用户表中
    if(nameflag==true&&passwordflag==true)
    {
     QString inputname=ui->LineEdit->text();
     QString inputpasswd=ui->LineEdit_2->text();
     //插入数据:用到了位置绑定实现插入
     query.prepare("insert into qquserdata values (?, ?)");
     query.addBindValue(inputname);   //插入账户名信息
     query.addBindValue(inputpasswd); //插入密码信息
     if(query.exec())
     qDebug()<<"注册成功！";
    }
    else
    qDebug()<<"注册失败！" ;
    this->close();

}

void Register::on_pushButton_clicked()
{
  this->close();
}
