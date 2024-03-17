#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_calendarWidget_selectionChanged()
{
    //获取日期
    QDate date = ui->calendarWidget->selectedDate();
    //显示日期
    ui->label->setText(date.toString());
}
