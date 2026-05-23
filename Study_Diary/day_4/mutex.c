#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t mutex;
int count=0;
void *fun1(void *arg)
{
    
    for(int i=0;i<5;i++)
    {
        pthread_mutex_lock(&mutex);
        printf("fun1 print %d\n",count++);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_detach(pthread_self());
}
void *fun2(void *arg)
{
    
    for(int i=0;i<5;i++)
    {
        pthread_mutex_lock(&mutex);
        printf("fun2 print %d\n",count++);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_detach(pthread_self());
}
int main(int argc,char *argv[])
{
    pthread_mutex_init(&mutex,NULL);
    pthread_t tid1,tid2;
    int ret1=pthread_create(&tid1,NULL,fun1,NULL);
    int ret2=pthread_create(&tid2,NULL,fun2,NULL);
    pthread_exit(NULL);
}
