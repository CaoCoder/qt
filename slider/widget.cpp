#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QShortcut>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->horizontalSlider->setMinimum(500);
    ui->horizontalSlider->setMaximum(2000);

    ui->horizontalSlider->setValue(1000);

    //设置垂直滑动条的滑块方向。从下往上。
    ui->verticalSlider->setInvertedAppearance(true);
    //设置上箭头的快捷键
    QShortcut* shortcut = new QShortcut(this);
    shortcut->setKey(QKeySequence(Qt::Key_Up));
    connect(shortcut, &QShortcut::activated, this, &Widget::addValue);
}

Widget::~Widget()
{
    delete ui;
}

//定义改变宽度的槽函数
void Widget::addValue()
{
    int value = ui->horizontalSlider->value();
    ui->horizontalSlider->setValue(value-20);
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    //随着滑动条值的增加或者减小改变窗口宽度
    QRect rect = this->geometry();
    this->setGeometry(rect.x(), rect.y(), value, rect.height());

    qDebug() << value;
}
