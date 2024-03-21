#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->addItem("c++");
    ui->listWidget->addItem("java");
}

Widget::~Widget()
{
    delete ui;
}

