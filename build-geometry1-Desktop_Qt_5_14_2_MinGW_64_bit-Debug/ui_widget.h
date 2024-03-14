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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_refuse;
    QPushButton *pushButton_accept;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        pushButton_refuse = new QPushButton(Widget);
        pushButton_refuse->setObjectName(QString::fromUtf8("pushButton_refuse"));
        pushButton_refuse->setGeometry(QRect(350, 229, 80, 51));
        pushButton_accept = new QPushButton(Widget);
        pushButton_accept->setObjectName(QString::fromUtf8("pushButton_accept"));
        pushButton_accept->setGeometry(QRect(150, 230, 80, 51));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 120, 131, 51));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_refuse->setText(QCoreApplication::translate("Widget", "\346\213\222\347\273\235", nullptr));
        pushButton_accept->setText(QCoreApplication::translate("Widget", "\345\220\214\346\204\217", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\202\271\345\207\273\346\213\222\347\273\235\346\214\211\351\222\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
