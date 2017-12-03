#ifndef QQDIALOG_H
#define QQDIALOG_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDialog>
#include <QDebug>
#include <QDialog>

namespace Ui {
class QQDialog;
}

class QQDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QQDialog(QWidget *parent = 0);
    ~QQDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QQDialog *ui;
};

static bool createConnection()
{
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("my1.db");
    if (!db1.open()) {
       qDebug()<<QObject::tr("打开数据库失败");
        return false;
    }
    QSqlQuery query;
       query.exec("create table login (account varchar(20) primary key, "
                   "password varchar(20))");
       query.exec("insert into student values('10475615', '666666')");
       query.exec("insert into student values('10475616', '666666')");
       query.exec("insert into student values('10475617', '666666')");
       return true;
}

#endif // QQDIALOG_H
