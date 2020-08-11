  #include "enroll.h"
#include "ui_enroll.h"
#include<QDebug>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>

Enroll::Enroll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Enroll)
{
    ui->setupUi(this);
    connect(ui->pushButton_4,SIGNAL(pressed()),this,SLOT(deal_submit()));

}

Enroll::~Enroll()
{
    delete ui;
}

void Enroll::deal_submit()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("39.105.82.172");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("jx19991022");
    db.setDatabaseName("fund_account");
    if(!db.open()){
        QMessageBox::warning(this,"错误",db.lastError().text());
        qDebug()<<db.lastError().text();
        return;
    }
    QString name = ui->lineEdit->text();
    QString passwd = ui->lineEdit_2->text();
    float balance = ui->lineEdit_3->text().toFloat();
    QString str = QString("insert into account (name,passwd,balance) values('%1','%2',%3)").arg(name).arg(passwd).arg(balance);
    QSqlQuery query;
    query.exec(str);
    qDebug()<<"提交成功";
    this->hide();
    db.close();
    emit call_widget();
}
