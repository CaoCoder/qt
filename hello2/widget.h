#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void handleClick();
private:
    Ui::Widget *ui;
    //添加成员变量
     QPushButton* myButton = new QPushButton(this);
};
#endif // WIDGET_H
