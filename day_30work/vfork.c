#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int gv=30;
void main()
{
	pid_t pid,ppid;
	pid=vfork();
	if(pid>0)
	{
		printf("this is parent process and pid is %d\n",getpid());
		printf("the pid in parent after vfork is %d\n",pid);
			printf("11111\n");
			printf("gv value is %d\n",gv);
			sleep(2);
			exit(0);
	}
	else if(pid==0)
	{
		printf("this is child process and pid is %d\n",getpid());
		printf("the pid in child after vfork is %d\n",pid);
		printf("ppid is %d\n",getppid());
		gv=10;
			printf("222\n");
			printf("gv value n child is %d\n",gv);
			sleep(2);
			exit(0);

	}
	else if(pid<0)
		printf("vfork s.c is fail to create child process\n");
	while(1)
		;

}
