#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("吃的1");
    ui->comboBox->addItem("吃的2");

    ui->comboBox_2->addItem("食物的1");
    ui->comboBox_2->addItem("食物的2");
    ui->comboBox_3->addItem("的1");
    ui->comboBox_3->addItem("的2");


    ui->spinBox->setValue(1);
    ui->spinBox_2->setValue(1);
    ui->spinBox_3->setValue(1);
    ui->spinBox->setMaximum(5);
    ui->spinBox->setRange(1,6);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug() << ui->comboBox->currentText() << ui->spinBox->value();
}
