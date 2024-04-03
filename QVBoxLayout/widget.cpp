#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建三个按钮
    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    QPushButton* btn3 = new QPushButton("按钮3");
    //舒展开
    btn1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //创建布局管理器
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);


    //把布局管理器设置到widget
    this->setLayout(layout);

    //创建子layout
    QHBoxLayout* layoutChild = new QHBoxLayout();

    //添加两个按钮进去
    QPushButton* btn4 = new QPushButton("按钮4");
    QPushButton* btn5 = new QPushButton("按钮5");
    //舒展开
    btn4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layoutChild->addWidget(btn4);
    layoutChild->addWidget(btn5);
    //嵌套添加到处置布局管理器中
    layout->addLayout(layoutChild);
}

Widget::~Widget()
{
    delete ui;
}

