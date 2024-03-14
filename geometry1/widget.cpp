#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(0));
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_accept_clicked()
{
    ui->label->setText("你点击按钮吧");
}

void Widget::on_pushButton_refuse_clicked()
{

}

void Widget::on_pushButton_refuse_pressed()
{
    int width = this->geometry().width();
    int height = this->geometry().height();

    int x = rand() % width;
    int y = rand() % height;

    ui->pushButton_refuse->move(x, y);
}
