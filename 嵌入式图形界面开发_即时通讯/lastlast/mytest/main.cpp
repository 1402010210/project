#include "mywidget.h"
#include <QApplication>
#include "Mydialog.h"
#include "register.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    MyDialog dialog;
    char returnValue = dialog.exec();
    if(returnValue==QDialog::Accepted){
        w.show();
        return a.exec();
    }
    else return 0;
}
