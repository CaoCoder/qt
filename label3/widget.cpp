#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置文字居中对齐
    //    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //设置自动换行
    ui->label->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->label->setWordWrap(true);
//    ui->label->setText("踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩从踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩从");
    //设置首行缩进
    ui->label->setIndent(80);
     ui->label->setText("踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩从踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩踩从");
}

Widget::~Widget()
{
    delete ui;
}

