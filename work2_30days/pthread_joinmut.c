#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int glob=0;
void * thread_entry(void *ptr)
{
	int i,lop=*(int*)ptr,local;
	printf("my thread is invoked\n");
	for(i=0;i<=*(int*)ptr;i++)
	{
		local=glob;
		local++;
		glob=local;
	}
}
void *my_fun(void * arg)
{
	int i,loop,local;
	loop=*(int *)arg;
	printf("new thread invoked\n");
	for(i=0;i<=loop;i++)
	{
		local=glob;
		local++;
		glob=local;
	}
}
void main(void)
{
	void * ret;
	pthread_t t1,t2;
	int res,loop=2000,rc;
	rc=pthread_create(&t1,0,thread_entry,&loop);
	if(rc!=0)
		printf("fail to create new thread from this process\n");
	rc=pthread_create(&t2,0,my_fun,&loop);
	if(rc!=0)
		printf("fail to create new thread from this process\n");
	pthread_join(t1,&ret);
	pthread_join(t2,&ret);
	printf("val of glob is %d\n",glob);
}
