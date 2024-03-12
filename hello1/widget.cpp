#include "widget.h"
#include "ui_widget.h"
#include <QLineEdit>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //通过输入框创建hello word
//    QLineEdit* edit = new QLineEdit(this);
//    edit->setText("hello ");
    //通过按钮创建hell



//    QPushButton* btn = new QPushButton(this);
//    btn->setText("hello");
    connect(ui->Button, &QPushButton::clicked, this, &Widget::handleClick);
     //谁发出的信号， 发出的什么信号，  谁来处理这个信号，  信号怎么处理
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    //当按钮被点击之后，就把按钮中的文本更换
    if(ui->Button->text() == QString("hello"))
    {
          ui->Button->setText("hello qt");
    }
    else
    {
              ui->Button->setText("hello");
    }

}

