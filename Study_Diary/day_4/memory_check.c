#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p=(int*)malloc(sizeof(int)*4);
	
	
	for(int i=0;i<4;i++)
	{
		p[i]=i+1;
		printf("p[%d] = %d",i,p[i]);
	}
	
	return 0;
}
