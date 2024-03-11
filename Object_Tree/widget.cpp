#include "widget.h"
#include "ui_widget.h"
#include "mypushbutton.h"
#include <QDebug>
//Widget::Widget(QWidget *parent)
//    : QWidget(parent)
//{
//    MyPushBUtton* btn = new MyPushBUtton;
//    btn->setText("我的按钮");
//    btn->setParent(this);
//}

//Widget::~Widget()
//{
//    qDebug() << "Widget的析构函数被调用。。";
//}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* btn1 = new QPushButton("按钮1", this);
    btn1->move(200, 300);

    qDebug() << "按钮1的坐标为:["<< btn1->x() << "," << btn1->y() << "]";
}
Widget::~Widget()
{
    delete ui;
}
