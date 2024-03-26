#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void main(void)
{
	pid_t pid,cpid;
	int *stat,i=100,x;
	stat=&x;
	pid=fork();
	if(pid==0)
	{
		printf("this is child process is %d\n",getpid());
		while(i)
		{
			printf("still running\n");
			sleep(0.10);
			i--;
			raise(19);
		}

	}
	else
	{
		cpid=waitpid(pid,stat,WCONTINUED);
		printf("the cpid is %d\n",cpid);
		printf("parent execution is finished\n");
	}
}
