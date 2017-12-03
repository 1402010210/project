#ifndef CHATDIALOG_H
#define CHATDIALOG_H
class QUdpSocket;
#include <QDialog>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = 0);
    ~ChatDialog();

private slots:
    void processPendingDatagram();
    void on_sendButton_clicked();

    void on_pushButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::ChatDialog *ui;
    QUdpSocket *sender;
    QUdpSocket *receiver;
    bool saveFile(const QString &fileName);
    void keyPressEvent(QKeyEvent *event);
    qint32 mport ;
    qint32 tport;
};


#endif // CHATDIALOG_H
