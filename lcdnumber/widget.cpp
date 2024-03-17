#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QProgressBar>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建QTimer
    timer = new QTimer(this);


    connect(timer, &QTimer::timeout, this, &Widget::updateTime);

    //启动QTimer，规定时间间隔100秒
    timer->start(100);
}

Widget::~Widget()
{
    delete ui;
}
//更新进度条
void Widget::updateTime()
{
    int value = ui->progressBar->value();
    if(value >= 100)
    {
        timer->stop();
        return ;
    }
    ui->progressBar->setValue(value+1);

}

