#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(deal_log_in())); //登录
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(deal_enroll())); //注册
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(deal_visitor()));//游客访问
    connect(&enroll_w,SIGNAL(call_widget()),this,SLOT(show()));       //登录窗口重现
}

Widget::~Widget()
{
    delete ui;
}

void Widget::deal_enroll()  //注册
{
    enroll_w.show();
    this->hide();
}

void Widget::deal_log_in()  //登录
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
    QString str_name = ui->lineEdit->text();
    QString str_passwd = ui->lineEdit_2->text();
    QString sql_get = QString("select passwd from account where name = '%1'").arg(str_name);
    QSqlQuery query;
    query.exec(sql_get);
    QString get_name,get_passwd;
    while(query.next()){
        get_passwd = query.value(0).toString();
        qDebug()<<get_passwd;
    }
    if(get_passwd=="")
        QMessageBox::warning(this,"错误","用户名不存在");
    else if(str_passwd == get_passwd){
        this->hide();
        log_in_w=new MainWidget();
        log_in_w->show();
        db.close();
    }
    else{
        QMessageBox::warning(this,"错误","密码错误");
    }
}

void Widget::deal_visitor() //游客访问
{
    this->hide();
    visitor_w=new Visitor_Widget();
    visitor_w->show();
}

