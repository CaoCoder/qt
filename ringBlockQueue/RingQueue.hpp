#include <iostream>
#include <vector>
#include <semaphore.h>
#include <ctime>
#include <unistd.h>
#include <pthread.h>
using namespace std;

const int gGap = 5;

template <class T>
class RingQueue
{
public:
    RingQueue(int cap = gGap)
        :ringqueue_(cap)
        ,pIndex_(0)
        ,cIndex_(0)
    {   
        //初始生产者可以使用的空间
        sem_init(&roomSem_, 0, ringqueue_.size());
        //消费
        sem_init(&dataSem_, 0, 0);

        pthread_mutex_init(&pmutex_, nullptr);
        pthread_mutex_init(&cmutex_, nullptr);

    }
    ~RingQueue()
    {
        sem_destroy(&roomSem_);
        sem_destroy(&dataSem_);

        pthread_mutex_destroy(&pmutex_);
        pthread_mutex_destroy(&cmutex_);
    }

    void push(const T& in)
    {
        sem_wait(&roomSem_);//如果队列空间满了就阻塞等，等什么？等待消费者通知。如果不满，空间-1

        pthread_mutex_lock(&pmutex_);
        ringqueue_[pIndex_] = in;//生产

        pIndex_++;//下标也是临界资源
        pIndex_ %= ringqueue_.size();//更新下标
        pthread_mutex_unlock(&pmutex_);

        sem_post(&dataSem_);//通知消费者有新的数据可用,数据+1
    
    }

    T pop()
    {
        sem_wait(&dataSem_);//如果为空，就阻塞，等待生产者生产。如果不空，数据-1

        pthread_mutex_lock(&cmutex_);
        T temp = ringqueue_[cIndex_];//消费
           cIndex_++;
        cIndex_ %= ringqueue_.size();

        pthread_mutex_unlock(&cmutex_);
        sem_post(&roomSem_);//如果生产者队列满了，则唤醒，可以生产了。如果不满，通知生产者空间多了一个，空间+1
     
        return temp;
    }
private:
    vector<T> ringqueue_;//循环队列
    sem_t roomSem_;//生产者的空间,计数器
    sem_t dataSem_;
    uint32_t pIndex_;
    uint32_t cIndex_;

    pthread_mutex_t pmutex_;
    pthread_mutex_t cmutex_;
};
