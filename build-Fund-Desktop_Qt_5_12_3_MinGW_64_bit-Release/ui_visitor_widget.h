/********************************************************************************
** Form generated from reading UI file 'visitor_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISITOR_WIDGET_H
#define UI_VISITOR_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Visitor_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QComboBox *comboBox;
    QPushButton *pushButton_5;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *Visitor_Widget)
    {
        if (Visitor_Widget->objectName().isEmpty())
            Visitor_Widget->setObjectName(QString::fromUtf8("Visitor_Widget"));
        Visitor_Widget->resize(400, 500);
        Visitor_Widget->setMaximumSize(QSize(400, 500));
        verticalLayout = new QVBoxLayout(Visitor_Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(Visitor_Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(0, 50));
        textBrowser->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(Visitor_Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser_2 = new QTextBrowser(widget_2);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setMinimumSize(QSize(0, 50));
        textBrowser_2->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(textBrowser_2, 0, 0, 1, 2);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 3, 1, 1, 1);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 4, 0, 1, 1);

        comboBox = new QComboBox(widget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 4, 1, 1, 1);

        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 5, 0, 1, 1);

        lcdNumber = new QLCDNumber(widget_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        gridLayout->addWidget(lcdNumber, 5, 1, 1, 1);


        verticalLayout->addWidget(widget_2);


        retranslateUi(Visitor_Widget);

        QMetaObject::connectSlotsByName(Visitor_Widget);
    } // setupUi

    void retranslateUi(QWidget *Visitor_Widget)
    {
        Visitor_Widget->setWindowTitle(QApplication::translate("Visitor_Widget", "Form", nullptr));
        textBrowser->setHtml(QApplication::translate("Visitor_Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600;\">\347\203\255\351\227\250\345\237\272\351\207\221\345\210\227\350\241\250</span></p></body></html>", nullptr));
        groupBox->setTitle(QApplication::translate("Visitor_Widget", "GroupBox", nullptr));
        textBrowser_2->setHtml(QApplication::translate("Visitor_Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600;\">\346\212\225\350\265\204\347\255\226\347\225\245\345\210\206\346\236\220</span></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("Visitor_Widget", "\345\237\272\351\207\221\344\273\243\347\240\201", nullptr));
        pushButton_2->setText(QApplication::translate("Visitor_Widget", "\344\271\260\345\205\245\346\227\245\346\234\237", nullptr));
        pushButton_3->setText(QApplication::translate("Visitor_Widget", "\345\215\226\345\207\272\346\227\245\346\234\237", nullptr));
        pushButton_4->setText(QApplication::translate("Visitor_Widget", "\347\255\226\347\225\245\351\200\211\346\213\251", nullptr));
        comboBox->setItemText(0, QApplication::translate("Visitor_Widget", "\346\257\217\346\227\245\345\256\232\346\212\225", nullptr));
        comboBox->setItemText(1, QApplication::translate("Visitor_Widget", "\346\231\272\350\203\275\345\256\232\346\212\225", nullptr));
        comboBox->setItemText(2, QApplication::translate("Visitor_Widget", "\316\240\345\256\232\346\212\225", nullptr));

        pushButton_5->setText(QApplication::translate("Visitor_Widget", "\346\224\266\347\233\212\350\256\241\347\256\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Visitor_Widget: public Ui_Visitor_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISITOR_WIDGET_H
