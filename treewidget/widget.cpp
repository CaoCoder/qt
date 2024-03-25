#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabel("动物");
    QTreeWidgetItem* item1 = new QTreeWidgetItem();
    item1->setText(0, "猫");
    ui->treeWidget->addTopLevelItem(item1);

    QTreeWidgetItem* item2 = new QTreeWidgetItem();
    item2->setText(0, "狗");
    ui->treeWidget->addTopLevelItem(item2);

    QTreeWidgetItem* item3 = new QTreeWidgetItem();
    item3->setText(0, "鸟");
    ui->treeWidget->addTopLevelItem(item3);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //获取输入框内容
    const QString& text = ui->lineEdit->text();
    if(text.isEmpty())
    {
        return;
    }
    //添加到顶层结点
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, text);
    ui->treeWidget->addTopLevelItem(item);
}

void Widget::on_pushButton_2_clicked()
{
    //获取输入框内容
    const QString& text = ui->lineEdit->text();
    //获取到选中的节点
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    if(currentItem == NULL)
    {
        return;
    }
    //构造新的item
    QTreeWidgetItem* newItem = new QTreeWidgetItem();
    newItem->setText(0, text);

    //添加item到选中节点
    currentItem->addChild(newItem);
    //展开父节点
    currentItem->setExpanded(true);
}
