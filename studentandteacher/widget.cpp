#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->tch = new teacher(this);
    this->stu = new student(this);

    //按钮
    QPushButton* btn = new QPushButton("上课了", this);
    resize(500,500);

    btn->move(100,100);

    connect(tch, &teacher::MySignal, stu, &student::StartStudy);

    connect(btn, &QPushButton::clicked, tch, &teacher::MySignal);

}

void Widget::EmitSignal()
{
    emit tch->MySignal();
}
Widget::~Widget()
{
    delete ui;
}

