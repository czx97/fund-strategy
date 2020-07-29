#include "visitor_widget.h"
#include "ui_visitor_widget.h"
#include<QComboBox>
#include<QDebug>

Visitor_Widget::Visitor_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Visitor_Widget)
{
    ui->setupUi(this);
}

Visitor_Widget::~Visitor_Widget()
{
    delete ui;
}

void Visitor_Widget::on_pushButton_5_clicked()
{
    code = ui->lineEdit->text();
    buy_date = ui->lineEdit_2->text();
    sell_date = ui->lineEdit_3->text();
    strategy_index = ui->comboBox->currentIndex();
}
