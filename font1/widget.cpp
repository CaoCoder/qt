#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel* label = new QLabel(this);
    label->setText("这是一段文本");

    //创建字体对象
    QFont font;
    font.setFamily("仿宋");
    font.setPixelSize(30);//像素大小
    font.setBold(true);//是否加粗
    font.setItalic(true);//倾斜
    font.setStrikeOut(true);//删除线

    //把font对象设置到label中
    label->setFont(font);
}

Widget::~Widget()
{
    delete ui;
}

