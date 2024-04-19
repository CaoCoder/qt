#include <queue>
#include <iostream>
#include <pthread.h>

#include <unistd.h>
using namespace std;

const uint32_t gDefaultCap = 5;

template <class T>
class BlockQueue
{
public:
    BlockQueue(uint32_t cap = gDefaultCap)
    :cap_(cap)
    ,bq_(cap)
    {
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&conCond_, nullptr);
        pthread_cond_init(&proCond_, nullptr);
    }
    ~BlockQueue()
    {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&conCond_);
        pthread_cond_destroy(&proCond_);
    }
    //生产者生产
    void push(const T& in)
    {
        lockQueue();
        while(isFull())
        {
            proBlockWait();
        }

        pushCore(in);
        unlockQueue();
        wakeupCon();
    }
    //消费
    T pop()
    {   
        lockQueue();
        if(isEmpty())
        {
            conBlockWait();
        }
        T tmp = popCore();

        unlockQueue();
        wakeupPro();

        return tmp;
    }
    void pushCore(const T& in)
    {
        bq_.push(in);
    }

    T popCore()
    {
        T tmp = bq_.front();
        bq_.pop();

        return tmp;
    }
public:
    void lockQueue()
    {
        pthread_mutex_lock(&mutex_);
    }
    void unlockQueue()
    {
        pthread_mutex_unlock(&mutex_);
    }


    bool isFull()
    {
        return bq_.size() == cap_;//cap_的作用是判满
    }
    bool isEmpty()
    {
        return bq_.empty();
    }
    void proBlockWait()
    {
        pthread_cond_wait(&proCond_, &mutex_);
    }
    void conBlockWait()
    {
        pthread_cond_wait(&conCond_, &mutex_);
    }

    void wakeupPro()
    {
        pthread_cond_signal(&proCond_);
    }
   void  wakeupCon()
    {
        pthread_cond_signal(&conCond_);
    }

private:
    queue<T> bq_;
    uint32_t cap_;
    pthread_mutex_t mutex_;
    pthread_cond_t conCond_;
    pthread_cond_t proCond_;
};