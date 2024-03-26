#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void main()
{
	pid_t cpid,pid;
	int i=1,c;
	pid=fork();
	if(pid==0)
	{
		printf("this is child process execution %d\n",getpid());
		while(i<12)
		{
			printf("here we goi\n");
			sleep(0.9);
			/*if(i=22)
			{
				printf("we will stop here\n");
				pause();	
				raise(18);
			}*/		
		}
	}
	else
	{
		printf("parent process\n");
		while(i<4)
		{
			printf("hi man\n");
			sleep(0.9);
			i++;
			alarm(8);
			if(i==23)
			{
			c=alarm(3);
			sleep(2);
			printf("here extented alarm and got return %d\n",c);
			}
		}
	}

}
