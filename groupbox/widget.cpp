#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("巨无霸");
    ui->comboBox->addItem("麦辣鸡腿堡");

    ui->comboBox_2->addItem("可口可乐");
    ui->comboBox_2->addItem("百事可乐");

    ui->comboBox_3->addItem("kun");
}

Widget::~Widget()
{
    delete ui;
}

