#pragma once
#include <iostream>
#include <pthread.h>
class Mutex
{
public:
    Mutex()
    {
        pthread_mutex_init(&_lock,nullptr);
    }

    void lock()
    {
        pthread_mutex_lock(&_lock);
    }
    void unlock()
    {
        pthread_mutex_unlock(&_lock);
    }
    ~Mutex()
    {
        pthread_mutex_destroy(&_lock);
    }
private:
    pthread_mutex_t _lock;
};

class lockguard
{
public:
    lockguard(Mutex* mutex)
        :_mutex(mutex)//初始化列表初始化锁
    {
        _mutex->lock();
    }
    ~lockguard()
    {
        _mutex->unlock();
    }
private:
    Mutex* _mutex;
};