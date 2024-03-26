#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int x=10;
void main()
{
	pid_t pid,ppid;
	pid=fork();
	if(pid==0)//child process
	{
		printf("this is child process %d\n",getpid());
		printf("this process pid from fork is %d\n",pid);
		printf("our parent pid is %d\n",getppid());
		printf("before modification of gv the add is %p and val is %d\n",&x,x);
		x=20;
		printf("after modification of gv the add is %p and val is %d\n",&x,x);
	}
	else if(pid>0)//parent process
	{
		printf("this is parent process %d\n",getpid());
		printf("this process child process is %d\n",pid);
		printf("our parent pid is %d\n",getppid());
		printf("the val of x is %d and add is %p\n",x,&x);
	}
	while(1)
		;
}
