#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QtDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* btn = new QPushButton(this);
    btn->setText("按钮");
    btn->move(200,300);
    //= 可以捕获所有变量
    connect(btn, &QPushButton::clicked, this, [=](){
        qDebug() << "我是lambda";
        this->setWindowTitle("我是lambda");//操控this
        btn->move(200,500);//操控btn
    });

}

Widget::~Widget()
{
    delete ui;
}

