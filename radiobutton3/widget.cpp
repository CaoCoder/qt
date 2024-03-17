#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
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


void Widget::on_radioButton_clicked(bool checked)
{
    qDebug() << "clicked bool" << checked;

}

void Widget::on_radioButton_2_pressed()
{
        qDebug() << "press";
}

void Widget::on_radioButton_3_released()
{
            qDebug() << "release";
}

//void Widget::on_radioButton_4_toggled(bool checked)
//{
//    qDebug() <<"ddd"<< checked;
//}

void Widget::on_radioButton_5_toggled(bool checked)
{
    qDebug() <<"ddd"<< checked;
}
