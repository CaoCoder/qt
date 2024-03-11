#include "mypushbutton.h"

#include <QDebug>
MyPushBUtton::MyPushBUtton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "我的按钮被构造函数调用";
}

MyPushBUtton::~MyPushBUtton()
{
    qDebug() << "我的析构函数被调用了";
}
