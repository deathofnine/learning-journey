#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
void *fun(void *arg)
{
	int n=0;
	while(1)
	{
		printf("%s\n",(char *)arg);
		n++;
		sleep(1);
		if(n==5)
		{
			pthread_exit((void*)"pthread has exit");
		}
	}
	return NULL;

}
int main(int argc,char *argv[])
{

	void *pthret;
	pthread_t tid;
	char arr[]="running...";
	int ret=pthread_create(&tid,NULL,fun,arr);
	
	pthread_join(tid,&pthret);
	printf("%s\n",(char*)pthret);
	return 0;
	
}
