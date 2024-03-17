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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QRadioButton *male;
    QRadioButton *fmale;
    QRadioButton *other;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        male = new QRadioButton(Widget);
        male->setObjectName(QString::fromUtf8("male"));
        male->setGeometry(QRect(250, 230, 111, 31));
        fmale = new QRadioButton(Widget);
        fmale->setObjectName(QString::fromUtf8("fmale"));
        fmale->setGeometry(QRect(250, 280, 111, 31));
        other = new QRadioButton(Widget);
        other->setObjectName(QString::fromUtf8("other"));
        other->setGeometry(QRect(250, 320, 111, 31));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 140, 121, 51));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        male->setText(QCoreApplication::translate("Widget", "\347\224\267", nullptr));
        fmale->setText(QCoreApplication::translate("Widget", "\345\245\263", nullptr));
        other->setText(QCoreApplication::translate("Widget", "\345\205\266\344\273\226", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\275\240\351\200\211\346\213\251\347\232\204\346\200\247\345\210\253\344\270\272:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
