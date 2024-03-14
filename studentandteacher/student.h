#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class student : public QObject
{
    Q_OBJECT
public:
    explicit student(QObject *parent = nullptr);

signals:

public slots:
    void StartStudy();//自定义槽函数

};

#endif // STUDENT_H
