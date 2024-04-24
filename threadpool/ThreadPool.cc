#include "ThreadPool.hpp"
#include "Task.hpp"
#include <ctime>

const std::string ops = "+-*/%";
int main()
{
    unique_ptr<ThreadPool<Task>> tp(new ThreadPool<Task>());

    tp->startCreateThreads();

     srand((unsigned long)time(nullptr) ^ getpid());
    //主线程派发任务
    while(true)
    {
       //制作任务
        int a = rand()%50;
        int b = rand()%10;
        char op = ops[rand() % ops.size()];

        Task t(a, b, op);
        tp->Push(t);//主线程派发
             cout << "producter[" << pthread_self() << "]" <<
        (unsigned long)time(nullptr) << "生产了一个任务"<< 
        a << op << b  << "=?" <<endl;

          sleep(1);
    }

}