#include "RingQueue.hpp"

void* producter(void* args)
{
    RingQueue<int>* rqp = static_cast<RingQueue<int>*>(args);
    while(true)
    {
        int data = rand() % 10;
        rqp->push(data);
        cout <<"pthread[" << pthread_self() << "]" << "生产了一个数据" <<data << endl;
  
    }
}
void* consumer(void* args)
{
    RingQueue<int>* rqp = static_cast<RingQueue<int>*>(args);
    while(true)
    {
              sleep(2);
        int data = rqp->pop();
       cout <<"pthread[" << pthread_self() << "]" << "消费了一个数据" <<data << endl;
       
    }
}
int main()
{
    srand((unsigned long)time(nullptr) ^ getpid());

    RingQueue<int> rq;

    pthread_t c,p;
    pthread_t c1,p1;
    pthread_create(&c, nullptr, consumer, &rq);
    pthread_create(&p, nullptr, producter, &rq);
    pthread_create(&c1, nullptr, consumer, &rq);
    pthread_create(&p1, nullptr, producter, &rq);

    pthread_join(p, nullptr);
    pthread_join(c, nullptr);
        
    pthread_join(p1, nullptr);
    pthread_join(c1, nullptr);
}