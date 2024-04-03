#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLabel* label = new QLabel(ui->tab);//label是子元素
    label->setText("标签⻚1");
    label->resize(100, 50);

    QLabel* label2 = new QLabel(ui->tab_2);
    label2->setText("标签页2");
    label->resize(100,50);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //获取当前有几个标签页
    int count = ui->tabWidget->count();
    //创建新的widget
    QWidget* w = new QWidget();
    ui->tabWidget->addTab(w, QString("tab") + QString::number(count + 1));
    //给widget中添加label
    QLabel* label = new QLabel(w);
    label->setText(QString("标签页") + QString::number(count + 1));
    label->resize(100, 50);
    //选中这个新的标签页
    ui->tabWidget->setCurrentIndex(count);
}

void Widget::on_pushButton_2_clicked()
{
    //获取当前标签页的下标
    int index = ui->tabWidget->currentIndex();
//删除这个标签页
    ui->tabWidget->removeTab(index);
}
