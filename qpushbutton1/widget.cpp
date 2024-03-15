#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QIcon>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建按钮
    QPushButton* btn = new QPushButton(this);
    btn->setText("按钮");
    btn->move(200, 300);
    //创建图标
    QIcon icon(":/caixukun.png");

    btn->setIcon(icon);

    //坤坤移动
    ui->kunkun->setIcon(icon);
    ui->kunkun->setIconSize(QSize(50,50));



    connect(btn, &QPushButton::clicked, this, &Widget::moveKunkun);
//      btn->setShortcut(QKeySequence("w"));
    btn->setShortcut(QKeySequence(Qt::Key_D));
    ui->pushButton->setShortcut(QKeySequence(Qt::Key_A));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::moveKunkun()
{
    //获取kunkun坐标
    QRect rect = ui->kunkun->geometry();
    //基于上次位置重新设置位置
    ui->kunkun->setGeometry(rect.x() + 5, rect.y(), rect.width(), rect.height());
}


void Widget::on_pushButton_clicked()
{
    //获取kunkun坐标
    QRect rect = ui->kunkun->geometry();
    //基于上次位置重新设置位置
    ui->kunkun->setGeometry(rect.x() - 5, rect.y(), rect.width(), rect.height());
}
