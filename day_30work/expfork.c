#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
int gv=20;
void main()
{
	int count=1;
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		printf("this parent process pid is %d and pid after fork is %d\n",getpid(),pid);
		gv=400;
		while(count)
		{
			count++;
			printf("%d break\n",gv);
			sleep(1.5);
		
		if(count==10)
		{
			printf("here it is kill\n");
			kill(getpid(),SIGKILL);
		}
		}
	}
	else if(pid==0)
	{
		printf("this child process pid is %d and pid after fork is %d\n",getpid(),pid);
		gv=500;
		while(1)
		{
			count++;
			printf("%d break\n",gv);
			sleep(1.5);
		
		if(count==10)
		{
			printf("it is killed\n");
			kill(getpid(),SIGKILL);
		}
		}

	}
	else if(pid<0)
	{
		printf("fork s.c is fail to create child process\n");
		exit(1);
	}

}
