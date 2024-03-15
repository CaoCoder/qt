#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //访问到图片文件
    QPixmap pixmap(":/1.jpg");

    //缩放图片
    pixmap = pixmap.scaled(30, 30);
    //构造一个光标对象
    QCursor cursor(pixmap, 10, 10);

    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

