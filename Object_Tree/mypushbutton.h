#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
class MyPushBUtton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushBUtton(QWidget *parent = nullptr);

    ~MyPushBUtton();
signals:

};

#endif // MYPUSHBUTTON_H
