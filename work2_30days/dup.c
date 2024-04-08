#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
void main(void)
{
	int fd,nfd;
	fd=open("sam.txt",O_RDWR);
	printf("new fd is %d\n",fd);
	//nfd=dup(fd);
	nfd=dup2(fd,1);
	close(fd);
	printf("dup val is %d and fd is %d\n",nfd,fd);
	write(nfd,"hi bye",6);
}
