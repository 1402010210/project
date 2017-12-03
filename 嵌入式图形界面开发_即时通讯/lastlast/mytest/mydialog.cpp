#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>
#include <QString>
#include <QMovie>
#include <QCompleter>
#include <QSqlDatabase>
#include <QStringList>
#include <register.h>
#include <QSqlQuery>
MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("登录界面"));
    this->setFixedSize( this->width (),this->height ());//固定框框大小
    ui->label_4->setPixmap(QPixmap(":/myImage/image/touxiang1.png"));
    QMovie *movie = new QMovie(":/myImage/image/loginback.gif");
    ui->label->setMovie(movie);     // 在标签中添加动画
    movie->start();
    QStringList wordList;
    wordList << "1047561576" << "1047561577" <<"1047561578"<<"1047561579" ;
    // 新建自动完成器
    QCompleter *completer = new QCompleter(wordList, this);
    // 设置大小写不敏感
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);
    connectdatabase();
}

void MyDialog::connectdatabase()
{
    //建立一个数据库连接
   QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
   //给数据库命名
    database.setDatabaseName("my.db");
    //打开数据库连接
        if(!database.open())
        {
            qDebug()<<"数据库打开失败！";
        }
        else
        {
            qDebug()<<"成功打开数据库！";
            QSqlQuery query;
            //查询当前数据库的表
            //数据库中已经有表的话，就不建表
            query.exec("select tbl_name name from sqlite_master where type = 'table'");
            while(query.next())
             {
                  tableflag=true;
                  qDebug()<<"当前数据库已有qquserdata表";
              }
            //没有表就创建表
            if(tableflag==false)
            {
                QSqlQuery query;
                if(query.exec("create table qquserdata (name varchar(20),password varchar(20))"))
                    qDebug()<<"qquserdata创建成功";
            }
        }
}
//匹配输入的账号密码和表中账号密码是否一致
bool MyDialog::equal(const QString &strname, const QString &strpassword)
{
    QSqlQuery query;
    query.exec(QString("select * from qquserdata where name = '%1' and password = '%2'").arg(strname, strpassword));
    return query.next();
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    //账号密码匹配一致的话，返回结果为true,则登录成功，转到好友列表去
    if(equal(name,password))
    {
        accept();
    }
    else if(name==""&&password=="")
    {
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle(QObject::tr("提示"));
        dialog->resize(140,80);
        dialog->setModal(true);
        QLabel *label = new QLabel(dialog);
        label->setText(QObject::tr("\n用户名、密码不可为空！"));
        dialog->show();
         }
    else
    {
            QDialog *dialog = new QDialog(this);
            dialog->setWindowTitle(QObject::tr("提示"));
            dialog->resize(140,80);
            dialog->setModal(true);
            QLabel *label = new QLabel(dialog);
            label->setText(QObject::tr("\n用户名或密码错误！"));
            dialog->show();
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
        }
}

void MyDialog::on_pushButton_3_clicked()
{
  this->close();
}

void MyDialog::on_regButton_clicked()
{
    //按下该按键，跳出注册界面
    Register r(this);
    r.show();
    r.exec();
}
