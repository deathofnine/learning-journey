#include<stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun(void *arg)
{
	while(1)
	{
		printf("%s\n",(char *)arg);
		sleep(5);

	}
	return NULL;
}
int main(int argc,char *argv[])
{

	pthread_t tid;
	int ret=pthread_create(&tid,NULL,fun,argv[0]);
	pthread_join(tid, NULL);
}
