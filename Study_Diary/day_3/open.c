#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main()
{
	int fd = open("/tmp/log.txt",O_WRONLY | O_CREAT | O_APPEND,0666);
	char buf[]="The program has started successfully\n";
	write(fd,buf,strlen(buf));
}
