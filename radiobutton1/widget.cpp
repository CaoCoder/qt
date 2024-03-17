#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

   ui->male->setChecked(true);//选中按钮

   ui->other->setCheckable(false);//是否能够选择
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_male_clicked()
{
    ui->label->setText("你选的性别为：男");
}

void Widget::on_fmale_clicked()
{
    ui->label->setText("你选的性别为:女");
}

void Widget::on_other_clicked()
{
      ui->label->setText("你选的性别为: 其他");
}
