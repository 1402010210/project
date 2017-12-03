#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>


namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_regButton_clicked();

private:
    Ui::MyDialog *ui;
public:
    bool tableflag=false;//是否创建表的标志
    void connectdatabase();
    bool equal(const QString &strname, const QString &strpassword);
};

#endif // MYDIALOG_H
