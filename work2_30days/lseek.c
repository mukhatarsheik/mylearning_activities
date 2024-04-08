#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
void main(void)
{
	int fd,f_c;
	char buf[30];
	fd=open("sam.txt",O_RDWR);
		printf("new fd is %d\n",fd);
		f_c=read(fd,buf,30);
		printf("the position of cur is %d\n",f_c);
		f_c=lseek(fd,2,SEEK_SET);
		printf("lseek for set beginning is %d\n",f_c);
		write(fd,"hi",2);
		f_c=lseek(fd,3,SEEK_CUR);
		printf("lseek for set current is %d\n",f_c);
		write(fd,"hi",2);
		f_c=lseek(fd,5,SEEK_END);
		printf("lseek for set end is %d\n",f_c);
		write(fd,"hi",2);
}
