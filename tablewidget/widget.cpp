#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setPlaceholderText("请输入新增的名字");
    //创建三行
    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);

    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("学号"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("姓名"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("年龄"));

    //设置初始数据
    ui->tableWidget->setItem(0,0, new QTableWidgetItem("1001"));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem("1002"));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //获取到行数
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
}


void Widget::on_pushButton_2_clicked()
{
    //获取列数
    int colCount = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(colCount);
    const QString& text = ui->lineEdit->text();
    //设置列名
      ui->tableWidget->setHorizontalHeaderItem(colCount, new QTableWidgetItem(text));
}

void Widget::on_pushButton_3_clicked()
{
    //获取到行数
    int rowCount = ui->tableWidget->rowCount();
    //删除选中行
    ui->tableWidget->removeRow(rowCount - 1);
}

void Widget::on_pushButton_4_clicked()
{
    //获取列数
    int colCount = ui->tableWidget->columnCount();
    ui->tableWidget->removeColumn(colCount - 1);
}
