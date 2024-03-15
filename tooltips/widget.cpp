#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置这两个按钮的 toolTips
    ui->pushButton->setToolTip("这是第一个按钮");
    ui->pushButton->setToolTipDuration(3000);//设置3秒
    //这里单位是msec(毫秒)，简称ms

    ui->pushButton_2->setToolTip("这是第二个按钮");

}

Widget::~Widget()
{
    delete ui;
}

