#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QDateTimeEdit>
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

void Widget::print1(QString& text)
{
     qDebug() << text;
}


void Widget::on_pushButton_clicked()
{
    QDateTime timeOld = ui->dateTimeEdit->dateTime();
    QDateTime timeNew = ui->dateTimeEdit_2->dateTime();

    int days = timeOld.daysTo(timeNew);//计算天数差值
    QString text = QString::number(days);//将数字转为字符串
    ui->pushButton->setText(text);
}
