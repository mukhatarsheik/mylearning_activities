#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main(int argc,int argv[])
{
	pid_t pid,cpid;
	printf("before converting\n");
	execl("/usr/bin/cat","usr/bin/cat","./basi.c",0);
	printf("i am still there \n");
}
