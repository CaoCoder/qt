#include "widget.h"
#include "ui_widget.h"
#include <QRegExpValidator>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建正则表达式对象  ^表示以什么开头，
    //一般以1开头，\d表示数字，不过\是转移字符，所以需要双斜杠。 {10}表示\d重复出现10次 $表示结尾
    QRegExp regexp("^1\\d{10}$");
    //注册验证器
    ui->lineEdit->setValidator(new QRegExpValidator(regexp));
    //然后编写逻辑
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineEdit_textEdited(const QString &text)
{
    QString content =text;
    int pos = 0;
    if(ui->lineEdit->validator()->validate(content, pos) == QValidator::Acceptable)
    {
        //验证通过
        ui->pushButton->setEnabled(true);
    }
    else
    {
        //验证不通过
        ui->pushButton->setEnabled(false);
    }
}
