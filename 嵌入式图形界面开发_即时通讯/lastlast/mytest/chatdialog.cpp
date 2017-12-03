#include "chatdialog.h"
#include "ui_chatdialog.h"
#include <QtNetwork>
#include <QKeyEvent>
#include <QScrollBar>
#include <QUdpSocket>
#include <QDateTime>
#include <QFileDialog>
#include  <QMessageBox>
extern QString otherport;
extern QString otherip;
extern QString myport;
ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("聊天框"));
    this->setStyleSheet("background-image:url(:/myImage/image/chatback.jpg)");
    ui->label_2->setPixmap(QPixmap(":/myImage/image/qqxiu.png"));
    bool ok;
    tport=otherport.toInt(&ok,10);
    mport=myport.toInt(&ok,10);
    ui->otheriplabel->setText(otherip);
    ui->otherportlabel->setText(otherport);
    ui->myportlabel->setText(myport);
    sender = new QUdpSocket(this);
    receiver = new QUdpSocket(this);
    receiver->bind(tport, QUdpSocket::ShareAddress);
    connect(receiver, &QUdpSocket::readyRead, this, &ChatDialog::processPendingDatagram);

}

ChatDialog::~ChatDialog()
{
    delete ui;
}

void ChatDialog::processPendingDatagram()
{
    while(receiver->hasPendingDatagrams())
    {
        QByteArray datagram1;

        // 让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
        datagram1.resize(receiver->pendingDatagramSize());

        // 接收数据报，将其存放到datagram中
        receiver->readDatagram(datagram1.data(), datagram1.size());
        //设置文本颜色为绿色
        ui->newstextBrowser->setTextColor(Qt::green);
        //设置个滚动条
        ui->newstextBrowser->verticalScrollBar()->setValue(ui->newstextBrowser->verticalScrollBar()->maximum());
        QString time1 = QDateTime::currentDateTime().toString("对方 yyyy-MM-dd hh:mm:ss");
        ui->newstextBrowser->append(time1);
        ui->newstextBrowser->append(datagram1);
    }
}

void ChatDialog::on_sendButton_clicked()
{
    QString time2 = QDateTime::currentDateTime().toString("我 yyyy-MM-dd hh:mm:ss");
    //实现中文通信
    QByteArray datagram2=ui->newsTextEdit->toPlainText().toUtf8();
    ui->newstextBrowser->setTextColor(Qt::blue);
    ui->newstextBrowser->append(time2);
    ui->newstextBrowser->append(datagram2);
    sender->writeDatagram(datagram2.data(),datagram2.size(),QHostAddress(otherip),mport);
    ui->newsTextEdit->clear();

}

void ChatDialog::on_pushButton_clicked()
{
    if (ui->newstextBrowser->document()->isEmpty())
    {
        QMessageBox::warning(0, tr("注意"), tr("聊天记录为空，请写入信息再保存！"), QMessageBox::Ok);
    }
    else
    {
        QString fileName = QFileDialog::getSaveFileName(this,tr("保存聊天记录"), tr("聊天信息"), tr("文本(*.txt);;All File(*.*)"));
        if(!fileName.isEmpty())
          {

            saveFile(fileName);
         QMessageBox::information(0, tr("提示"), tr("成功保存聊天记录！"), QMessageBox::Ok);
         }
        else
             QMessageBox::information(0, tr("提示"), tr("聊天记录未保存！"), QMessageBox::Ok);
    }
}

bool ChatDialog::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly  | QIODevice::Text)) {
        qDebug() << file.errorString();
        return false;
    }
    QTextStream out(&file);
    out << ui->newstextBrowser->toPlainText();

    return true;
}

void ChatDialog::keyPressEvent(QKeyEvent *event)//键盘按下事件
{
    if(event->modifiers() == Qt::ControlModifier)
    { // 是否按下Ctrl键
            if(event->key() == Qt::Key_Return)              // 是否按下中间的enter键
             on_sendButton_clicked();
    }
}


void ChatDialog::on_closeButton_clicked()
{
    this->close();
}
