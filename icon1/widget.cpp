#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置图标
    QIcon icon(":/1.jpg");//注意反斜杠在c++中是转义字符，所以推荐使用正斜杠。
    this->setWindowIcon(icon);

}

Widget::~Widget()
{
    delete ui;
}

