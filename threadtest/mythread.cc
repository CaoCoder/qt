#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "LockGuard.h"
using namespace std;
int tick = 100;
Mutex mutex1;
void* callback(void* args)
{
   
    const char* name = static_cast<const char*>(args);
    while(true)
    {
        cout << name << " 是我啊" << endl;
         {
            lockguard  lg(&mutex1);
            tick--;
            if(tick <= 0)
            {
                break;
            }
         }
         cout << tick << endl;
        sleep(0.5);
    }
    
}
int main()
{
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, nullptr, callback, (void*)"thread 1");
    pthread_create(&tid2, nullptr, callback, (void*)"thread 2");
    usleep(1000);
    // while(true)
    // {
    //     cout << "我是主线程" << endl;
    //     sleep(1.1);
    // }
    // pthread_cancel(tid1);
    // pthread_cancel(tid2);


    pthread_join(tid1, nullptr);
    pthread_join(tid2, nullptr);
    return 0;
}