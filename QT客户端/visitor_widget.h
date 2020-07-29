#ifndef VISITOR_WIDGET_H
#define VISITOR_WIDGET_H

#include <QWidget>
#include<QString>

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
    void on_pushButton_5_clicked();

private:
    Ui::Visitor_Widget *ui;
    QString code;
    QString buy_date;
    QString sell_date;
    int strategy_index;

};

#endif // VISITOR_WIDGET_H
