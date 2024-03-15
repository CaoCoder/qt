#include "widget.h"
#include "ui_widget.h"

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
    //设置窗口的样式
    this->setStyleSheet("background-color: white;");
    //设置输入框样式 color代表文本框的 字体颜色
    ui->lineEdit->setStyleSheet("background-color: rgb(240,240,240); color: black;");
    //设置按钮样式
    ui->pushButton->setStyleSheet("color: black");
       ui->pushButton_2->setStyleSheet("color: black");
}

void Widget::on_pushButton_2_clicked()
{
    //设置窗口的样式
    this->setStyleSheet("background-color: black;");
    //设置输入框样式 color代表文本框的 字体颜色
    ui->lineEdit->setStyleSheet("background-color: black; color: white;");
    //设置按钮样式
    ui->pushButton->setStyleSheet("color: white");
       ui->pushButton_2->setStyleSheet("color: white");
}


