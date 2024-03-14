#include "student.h"
#include <QDebug>
student::student(QObject *parent) : QObject(parent)
{

}

void student::StartStudy()
{
    qDebug() << "回到座位学习";
}
