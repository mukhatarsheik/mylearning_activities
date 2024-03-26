#include<stdio.h>
#include<unistd.h>
void main()
{
	
		int ppid,pid;
		pid=getpid();
		printf("this process pid is %d\n",pid);
		ppid=getppid();
		printf("the parent ppid is %d\n",ppid);
	while(1)
		;
	
}
