#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_radioButton_clicked()
{
    qDebug() << "clicked";

void Widget::on_radioButton_2_pressed()
{

}

void Widget::on_radioButton_3_released()
{

}

void Widget::on_radioButton_4_toggled(bool checked)
{

}
