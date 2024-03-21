#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //允许转圈
    ui->dial->setWrapping(true);
    //设置刻度线
    ui->dial->setNotchesVisible(true);

    // 设置最⼤值为
    ui->dial->setMaximum(100);
    // 设置最⼩值为
    ui->dial->setMinimum(0);

    ui->dial->setValue(100);//设置初始值



}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_dial_valueChanged(int value)
{
    //记得强转
    this->setWindowOpacity((double)value/100);
}
