#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("小猫");
    ui->comboBox->addItem("大猫");

    ui->comboBox_2->addItem("xiaonaio");
    ui->comboBox_2->addItem("daniao");

    ui->comboBox_3->addItem("xiaonaio");
    ui->comboBox_3->addItem("daniao");

    QPushButton* btn = new QPushButton("按钮", this);
    btn->move(500,300);
    connect(btn, &QPushButton::clicked, this, &Widget::handle);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    qDebug() << ui->comboBox->currentText();
    qDebug() << ui->comboBox_2->currentText();
    qDebug() << ui->comboBox_3->currentText();
}

