#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void * thread_entry(void *ptr)
{
	int i;
	printf("my thread is invoked\n");
	for(i=0;i<=*(int*)ptr;i++)
	printf("i val is %d\n",i);
}
void main(void)
{
	pthread_t thread1;
	int i,ret,lop=1000;
	printf("before thread creation\n");
	ret=pthread_create(&thread1,0,thread_entry,&lop);
	if(ret!=0)
	{
		printf("fail to create new thread from this process\n");
		exit(1);
	}
	sleep(1);
	//pthread_exit(&ret);
}
