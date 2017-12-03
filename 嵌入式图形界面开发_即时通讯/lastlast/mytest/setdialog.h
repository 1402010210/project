#ifndef SETDIALOG_H
#define SETDIALOG_H

#include <QDialog>

namespace Ui {
class SetDialog;
}

class SetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetDialog(QWidget *parent = 0);
    ~SetDialog();

private slots:

    void on_YESButton_clicked();

    void on_backButton_clicked();

private:
    Ui::SetDialog *ui;
};

#endif // SETDIALOG_H
