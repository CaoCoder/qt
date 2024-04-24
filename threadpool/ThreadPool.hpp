#include <iostream>
#include <pthread.h>
#include <queue>
#include <memory>
#include <unistd.h>
using namespace std;

int gThreadNum = 5;

template <class T>
class ThreadPool
{
public:
    ThreadPool(int threadNum = gThreadNum)
        :isStart_(false)
        ,threadNum_(threadNum)
    {
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&cond_, nullptr);
    }

    static void* threadRoutine(void* args)
    {
        pthread_detach(pthread_self());//线程分离，自己释放，不需要等待
        ThreadPool<T>* tp = static_cast<ThreadPool<T>* >(args);
        while(true)
        {
             sleep(6);
            tp->lockQueue();
            if(!tp->taskEmpty())
            {
                tp->waitForTask();
            }
            //消费任务，也就是把任务交给某个线程处理
            T t = tp->pop();

            tp->unlockQueue();

         int result = t.run();//所有任务都必须在临界区外处理
        int a,b;
        char op;
        t.get(&a, &b, &op);

        
        cout << "消费者[" << pthread_self() << "]" <<
        (unsigned long)time(nullptr) << "消费了一个任务"<< 
        a << op << b << "=" << result <<endl;
        }
    }
    //线程创建
    void startCreateThreads()
    {
        if(isStart_ == true)
        {
            cout << "重复启动了，0" << endl;
            return;
        }
        //创建五个线程
        for(int i = 0; i < threadNum_; i++)
        {
            pthread_t temp;
            //传递this指针，就是ThreadPool<T>*
            pthread_create(&temp, nullptr, threadRoutine, this);
        }
        isStart_ = true;
    }

    ~ThreadPool()
    {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&cond_);
    }

    void Push(const T& in)
    {
        lockQueue();
        taskQueue_.push(in);
        signalThread();//通知线程
        unlockQueue();
    }
    
private:
    void lockQueue()
    {
        pthread_mutex_lock(&mutex_);
    }
    void unlockQueue()
    {
        pthread_mutex_unlock(&mutex_);
    }
    bool taskEmpty()
    {
        return taskQueue_.empty();
    }
    void waitForTask()
    {
        pthread_cond_wait(&cond_, &mutex_);
    }
    void signalThread()
    {
        pthread_cond_signal(&cond_);
    }
    T pop()
    {
        T tmp = taskQueue_.front();
        taskQueue_.pop();

        return tmp;
    }
private:
    bool isStart_;
    int threadNum_;
    queue<T> taskQueue_;
    pthread_mutex_t mutex_;
    pthread_cond_t cond_;
};