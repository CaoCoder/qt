/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_passwd;
    QLineEdit *lineEdit_phone;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 250, 54, 12));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 290, 54, 12));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 330, 54, 12));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 380, 54, 12));
        lineEdit_name = new QLineEdit(Widget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(200, 250, 113, 20));
        lineEdit_passwd = new QLineEdit(Widget);
        lineEdit_passwd->setObjectName(QString::fromUtf8("lineEdit_passwd"));
        lineEdit_passwd->setGeometry(QRect(200, 290, 113, 20));
        lineEdit_phone = new QLineEdit(Widget);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(200, 380, 113, 20));
        radioButton = new QRadioButton(Widget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(210, 330, 91, 18));
        radioButton_2 = new QRadioButton(Widget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(270, 330, 91, 18));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 440, 151, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\247\223\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\200\247\345\210\253", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\347\224\265\350\257\235", nullptr));
        lineEdit_passwd->setText(QString());
        radioButton->setText(QCoreApplication::translate("Widget", "\347\224\267", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "\345\245\263", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
