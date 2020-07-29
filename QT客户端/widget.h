#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"enroll.h"
#include"mainwidget.h"
#include"visitor_widget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected slots:
    void deal_enroll();  //注册新账户
    void deal_log_in();  //登录操作
    void deal_visitor(); //游客登录

private:
    Ui::Widget *ui;
    Enroll enroll_w;
    MainWidget *log_in_w;
    Visitor_Widget *visitor_w;
};

#endif // WIDGET_H
