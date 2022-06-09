#include <iostream>
#include <pthread.h>
#include <cstdlib>

using namespace std;

#define NUM_THREAD 5

void* say_hello(void* args)
{
    cout << "Hello World!" << endl;
    return 0;
}

void* PrintHello(void* threadid)
{
    int tid = *((int *)threadid);
    cout << "Hello Runoob! 线程 ID, " << tid << endl;
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t tids[NUM_THREAD];
    int indexes[NUM_THREAD];
    int rc;
    int i;
    for(i = 0; i < NUM_THREAD; i++)
    {
        cout << "main() : 创建线程, " << i << endl;
        indexes[i] = i;
        // rc = pthread_create(&tids[i], NULL, PrintHello, (void*)&(indexes[i]));
        rc = pthread_create(tids+i, NULL, PrintHello, (void*)(indexes+i));
        if (rc)
        {
            cout << "Error:无法创建线程," << rc << endl;
            exit(-1);
        }
        // int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        // if(ret != 0)
        // {
        //     cout << "pthread_create error: error_code=" << ret << endl;
        // }
    }
    pthread_exit(NULL);
    return 0;
}
