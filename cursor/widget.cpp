#include "widget.h"
#include "ui_widget.h"
#include <QCursor>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QCursor cur(Qt::WaitCursor);
    ui->pushButton->setCursor(cur);
}

Widget::~Widget()
{
    delete ui;
}

