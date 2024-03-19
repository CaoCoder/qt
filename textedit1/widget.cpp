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


//文本框改变
void Widget::on_textEdit_textChanged()
{
    qDebug() << "[textChanged]" << ui->textEdit->toPlainText();
}


//鼠标选中改变
void Widget::on_textEdit_selectionChanged()
{
    const QTextCursor& cursor = ui->textEdit->textCursor();
    qDebug() << "[cursorPositionChanged]" << cursor.position();
}

//光标改变
void Widget::on_textEdit_cursorPositionChanged()
{
    const QTextCursor& cursor = ui->textEdit->textCursor();
    qDebug() << "[cursorPositionChanged]" << cursor.position();
}
//撤销是否可用
void Widget::on_textEdit_undoAvailable(bool b)
{
    qDebug() << "[undoAvailable]" << b;
}

//返回撤销是否可用

void Widget::on_textEdit_redoAvailable(bool b)
{
    qDebug() << "[redoAvailable]" << b;
}
