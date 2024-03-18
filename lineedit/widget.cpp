#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //初始化第一个输入框
    ui->lineEdit_name->setPlaceholderText("请输入姓名");

    //清空按钮
    ui->lineEdit_name->setClearButtonEnabled(true);


    ui->lineEdit_passwd->setText("请输入密码");//设置占位显示
    ui->lineEdit_passwd->setClearButtonEnabled(true);//设置清空按钮
    ui->lineEdit_passwd->setEchoMode(QLineEdit::Password);//设置密码模式


    ui->lineEdit_phone->setText("请输入电话");//设置占位显示
    ui->lineEdit_phone->setClearButtonEnabled(true);//设置清空按钮
    //校验格式 0代表数字
    ui->lineEdit_phone->setInputMask("000-0000-0000");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString s = ui->radioButton->isChecked() ? "男" : "女";
    qDebug() << ui->lineEdit_name->text();
    qDebug() << ui->lineEdit_phone->text();
    qDebug() << ui->lineEdit_passwd->text() << endl
              << s;

}
