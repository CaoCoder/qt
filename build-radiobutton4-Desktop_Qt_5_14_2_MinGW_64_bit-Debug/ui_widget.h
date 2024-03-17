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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        radioButton_1 = new QRadioButton(Widget);
        radioButton_1->setObjectName(QString::fromUtf8("radioButton_1"));
        radioButton_1->setGeometry(QRect(90, 220, 91, 18));
        radioButton_2 = new QRadioButton(Widget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(90, 270, 91, 18));
        radioButton_3 = new QRadioButton(Widget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(90, 320, 91, 18));
        radioButton_4 = new QRadioButton(Widget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(250, 220, 91, 18));
        radioButton_5 = new QRadioButton(Widget);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(250, 270, 91, 18));
        radioButton_6 = new QRadioButton(Widget);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(430, 220, 91, 18));
        radioButton_7 = new QRadioButton(Widget);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));
        radioButton_7->setGeometry(QRect(430, 270, 91, 18));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        radioButton_1->setText(QCoreApplication::translate("Widget", "1", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "2", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Widget", "3", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Widget", "4", nullptr));
        radioButton_5->setText(QCoreApplication::translate("Widget", "5", nullptr));
        radioButton_6->setText(QCoreApplication::translate("Widget", "6", nullptr));
        radioButton_7->setText(QCoreApplication::translate("Widget", "7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
