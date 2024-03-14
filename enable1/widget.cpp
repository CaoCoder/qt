#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* btn = new QPushButton(this);
    btn->move(200,300);
    btn->setText("我是按钮");
    btn->setEnabled(false);//设置为禁用状态
}

Widget::~Widget()
{
    delete ui;
}

