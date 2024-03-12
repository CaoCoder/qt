#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);//挂到对象树上
    button->setText("关闭");
    button->move(200, 300);

    connect()
}

Widget::~Widget()
{
    delete ui;
}

