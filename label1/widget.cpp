#include "widget.h"
#include "ui_widget.h"
#include <QResizeEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置文本格式
    ui->label->setTextFormat(Qt::PlainText);
    ui->label->setText("这是文本一");
    //设置为富文本
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setText("<b>这是文本2</b>");
    //设置为markdown
    ui->label_3->setTextFormat(Qt::MarkdownText);
    ui->label_3->setText("#  这是文本3");
    //设置和widget一样的大小
    ui->label->setGeometry(0,0,800, 600);
    QPixmap q(":/pr/caixukun.png");
    ui->label->setPixmap(q);

    ui->label->setScaledContents(true);



}
//重写resizeEvent,这个函数会在窗口大小变化时 被 自动调用
void Widget::resizeEvent(QResizeEvent *event)
{
    //重新设置新的尺寸
    ui->label->setGeometry(0,0, event->size().width(), event->size().height());

}

Widget::~Widget()
{
    delete ui;
}

