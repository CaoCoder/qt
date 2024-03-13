#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* btn = new QPushButton(this);
    btn->setText("按钮");
    btn->move(200, 300);

    connect(btn, &QPushButton::clicked, this, &Widget::hanld);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::hanld()
{
    this->setWindowTitle("按钮已经按下了");
}

