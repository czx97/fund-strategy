#ifndef ENROLL_H
#define ENROLL_H

#include <QWidget>

namespace Ui {
class Enroll;
}

class Enroll : public QWidget
{
    Q_OBJECT

public:
    explicit Enroll(QWidget *parent = nullptr);
    ~Enroll();
protected slots:
    void deal_submit();
signals:
    void call_widget();
private:
    Ui::Enroll *ui;
};

#endif // ENROLL_H
