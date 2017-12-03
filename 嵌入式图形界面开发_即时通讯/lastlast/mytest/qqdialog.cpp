#include "qqdialog.h"
#include "ui_qqdialog.h"
#include <QDebug>
#include <QString>
#include <QMovie>
#include <QCompleter>
#include <QSqlDatabase>
#include <QStringList>

QQDialog::QQDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QQDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("登录界面"));
    ui->label_4->setPixmap(QPixmap(":/myImage/image/qq.jpg"));
    ui->label->setPixmap(QPixmap(":/myImage/image/qqbackground.png"));
    //QMovie *movie = new QMovie(":/myImage/image/loginback.gif");
    //ui->label->setMovie(movie);     // 在标签中添加动画
    //movie->start();
    QStringList wordList;
    wordList << "10475615" << "10475616" <<"10475617" ;
    // 新建自动完成器
    QCompleter *completer = new QCompleter(wordList, this);
    // 设置大小写不敏感
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);

}

QQDialog::~QQDialog()
{
    delete ui;
}

void QQDialog::on_pushButton_clicked()
{
    QString account=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    if (!createConnection())
        qDebug()<<"连接失败";
       QSqlQuery query;
       query.exec("select * from login");
       while(query.next())
       {
           if(account==query.value(0).toString()&&password==query.value(1).toString())
           {
             accept();
       }
           else
            {  QDialog *dialog = new QDialog(this);
               dialog->setWindowTitle(QObject::tr("提示"));
               dialog->resize(250,50);
               dialog->setModal(true);
               QLabel *labell = new QLabel(dialog);
               labell->setText(QObject::tr("用户名或密码错误\n"));
               dialog->show();
               ui->lineEdit->clear();
               ui->lineEdit_2->clear();
           }
  }
}
