#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void my_func(int signo)
{
	if(signo==2)
	{
		printf("no int no float bro\n");
		sleep(1);
	}

	else if(signo==3)
		printf("never quit up\n");
	else if(signo==4)
		printf("never feel ill always kill");

}
void main()
{
	pid_t pid;
	int a=1,sigv;
	struct sigaction chg;
	chg.sa_handler=&my_func;
	chg.sa_flags=0;
	sigemptyset(&chg.sa_mask);
	sigaddset(&chg.sa_mask,2);
	sigaddset(&chg.sa_mask,3);
	sigaddset(&chg.sa_mask,4);
	sigaddset(&chg.sa_mask,5);
	//sigprocmask(SIG_BLOCK,&chg.sa_mask,0);
	sigaction(2,&chg,0);
	sigaction(3,&chg,0);
	sigaction(4,&chg,0);
	sigaction(5,&chg,0);
	pid=fork();
	if(pid==0)
	{
		printf("this child process execution\n");
		while(a)
		{
			a++;
			printf("thiis process is still running with %d\n",getpid());
			sleep(1);
		}
	}
	else 
	{
		printf("this parent process\n");
		while(1)
		{
			alarm(3);
			a=alarm(2);
			printf("parent process finish with a is %d\n",a);
			sleep(5);
		exit(0);
		}
	}

}
