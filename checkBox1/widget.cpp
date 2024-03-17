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


void Widget::on_pushButton_clicked()
{
    QString s1;
    if(ui->checkBox_eat->isChecked())
    {
        s1 += ui->checkBox_eat->text();
    }
    if(ui->checkBox_sleep->isChecked())
    {
        s1 += ui->checkBox_sleep->text();
    }
    if(ui->checkBox_video->isChecked())
    {
        s1 += ui->checkBox_video->text();
    }
    qDebug() << "今天的安排是"<< s1;
}
