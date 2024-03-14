#ifndef WIDGET_H
#define WIDGET_H
#include <teacher.h>
#include <student.h>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void EmitSignal();
private:
    Ui::Widget *ui;

    teacher* tch;//发送信号的对象
    student* stu;//接收信号的对象
};
#endif // WIDGET_H
