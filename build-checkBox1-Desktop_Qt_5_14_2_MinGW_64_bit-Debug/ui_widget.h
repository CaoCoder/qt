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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QCheckBox *checkBox_eat;
    QCheckBox *checkBox_sleep;
    QCheckBox *checkBox_video;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        checkBox_eat = new QCheckBox(Widget);
        checkBox_eat->setObjectName(QString::fromUtf8("checkBox_eat"));
        checkBox_eat->setGeometry(QRect(180, 220, 73, 18));
        checkBox_sleep = new QCheckBox(Widget);
        checkBox_sleep->setObjectName(QString::fromUtf8("checkBox_sleep"));
        checkBox_sleep->setGeometry(QRect(180, 270, 73, 18));
        checkBox_video = new QCheckBox(Widget);
        checkBox_video->setObjectName(QString::fromUtf8("checkBox_video"));
        checkBox_video->setGeometry(QRect(180, 320, 73, 18));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 380, 80, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        checkBox_eat->setText(QCoreApplication::translate("Widget", "\345\220\203\351\245\255", nullptr));
        checkBox_sleep->setText(QCoreApplication::translate("Widget", "\347\235\241\350\247\211", nullptr));
        checkBox_video->setText(QCoreApplication::translate("Widget", "\345\210\267\350\247\206\351\242\221", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
