#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建三个QButtonGroup
    QButtonGroup* g1 = new QButtonGroup(this);
     QButtonGroup* g2 = new QButtonGroup(this);
      QButtonGroup* g3 = new QButtonGroup(this);

      //加入组里
      g1->addButton(ui->radioButton_1);
      g1->addButton(ui->radioButton_2);
      g1->addButton(ui->radioButton_3);

      g2->addButton(ui->radioButton_4);
      g2->addButton(ui->radioButton_5);

      g3->addButton(ui->radioButton_6);
      g3->addButton(ui->radioButton_7);

}


Widget::~Widget()
{
    delete ui;
}

