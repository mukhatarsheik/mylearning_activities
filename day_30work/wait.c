#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void main(void)
{
	pid_t pid,cpid;
	pid= fork();
	int x,i=25,statloc=0;
	if(pid==-1)
        {
		printf("fail to create child process\n");
		exit(1);
        }
	if(pid==0)
	{
		x=1;
		printf("child process executing id %d\n",getpid());
		while(i)
		{
			printf("i will not stop today\n");
			i--;
			sleep(1);
			/*if(i=10)
				scanf("%d",&x);*/
		}
	}
	else
	{
		cpid=wait(&statloc);
		//printf("the stat of child is %d\n",cpid);
		x=6;
		if(WIFEXITED(statloc))
			printf("wif %d\n",WEXITSTATUS(statloc));
		else if(WIFSIGNALED(statloc))
			printf("check is %d\n",WTERMSIG(statloc));
		else if(WIFSTOPPED(statloc))
		//	printf(" stoped signo %d\n",statloc);
		WNOHANG;
	}
	/*for(i=x;i<x+5;i++)
	{
		printf("%d",i);
	}
	if(pid!=0)
		printf("\n");*/

}

