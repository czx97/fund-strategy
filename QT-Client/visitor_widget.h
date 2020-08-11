#ifndef VISITOR_WIDGET_H
#define VISITOR_WIDGET_H

#include <QWidget>
#include<QString>
#include<QTcpSocket>

namespace Ui {
class Visitor_Widget;
}

class Visitor_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Visitor_Widget(QWidget *parent = nullptr);
    ~Visitor_Widget();

private slots:
    void slot_send();
    void slot_recv();
    void slot_disconnect();

private:
    Ui::Visitor_Widget *ui;
    QString code;
    QString buy_date;
    QString sell_date;
    int strategy_index;
    QTcpSocket * tcp_socket;

};

#endif // VISITOR_WIDGET_H
