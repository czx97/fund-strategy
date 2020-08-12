#include "visitor_widget.h"
#include "ui_visitor_widget.h"
#include<QComboBox>
#include<QDebug>

Visitor_Widget::Visitor_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Visitor_Widget)
{
    ui->setupUi(this);
    tcp_socket = new QTcpSocket();
    tcp_socket->connectToHost("39.105.82.172",9999);
    connect(tcp_socket,&QTcpSocket::readyRead,this,&Visitor_Widget::slot_recv);        //处理接受信息
    connect(ui->pushButton_5,&QPushButton::clicked,this,&Visitor_Widget::slot_send);   //处理发送信息
    connect(tcp_socket,&QTcpSocket::disconnected,this,&Visitor_Widget::slot_disconnect);  //断开连接时释放及时socket
}

Visitor_Widget::~Visitor_Widget()
{
    delete ui;
}

//处理发送信息
void Visitor_Widget::slot_send()
{
    code = ui->lineEdit->text();
    buy_date = ui->lineEdit_2->text();
    sell_date = ui->lineEdit_3->text();
    strategy_index = ui->comboBox->currentIndex();
    QString send_msg = code+buy_date+sell_date+QString::number(strategy_index);
    tcp_socket->write(send_msg.toUtf8());
}
//处理接收参数
void Visitor_Widget::slot_recv()
{
    qDebug()<<"success";
    QString recv_msg = tcp_socket->readAll();
    qDebug()<<recv_msg;
    float range = recv_msg.toFloat();
    qDebug()<<range;
    ui->lcdNumber->setSmallDecimalPoint(false);
    ui->lcdNumber->setDigitCount(7);
    ui->lcdNumber->display(range);
}
//处理断开连接
void Visitor_Widget::slot_disconnect()
{
    tcp_socket->close();
    tcp_socket->deleteLater();
}



