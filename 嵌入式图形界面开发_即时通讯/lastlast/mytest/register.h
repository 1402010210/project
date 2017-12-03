#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();
    bool nameflag=false;    //用户名是否有效标志
    bool passwordflag=false;  //密码是否有效标志

private slots:

    void on_YesButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
