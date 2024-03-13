#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this, &Widget::mySignal, this , &Widget::handleMySignal);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleMySignal(const QString & text)
{
    this->setWindowTitle(text);
}


void Widget::on_pushButton_clicked ()
{
    emit mySignal("带参数的信号");
}
