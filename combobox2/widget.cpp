#include "widget.h"
#include "ui_widget.h"
#include <fstream>
#include <iostream>
#include <QDebug>
#include <QString>
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ifstream file("E:\\qt_code\\qt\\combobox2/1.txt");

    if(file.is_open() == NULL)
    {
        qDebug() << "打开文件失败";
    }
    string s;

    while(getline(file, s))
    {
          ui->comboBox->addItem(QString::fromStdString(s));
    }

file.close();

}

Widget::~Widget()
{
    delete ui;
}

