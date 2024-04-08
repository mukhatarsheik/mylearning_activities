#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int glob=0;
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;//declaration and initialization of mutex variable/object
void * thread_entry(void *ptr)
{
	int i,lop=*(int*)ptr,local;
	printf("thread_1 is invoked\n");
	for(i=0;i<=*(int*)ptr;i++)
	{
		pthread_mutex_lock(&mtx);
		local=glob;
		local++;
		glob=local;
		pthread_mutex_unlock(&mtx);
	}
}
void *my_fun(void * arg)
{
	int i,loop,local;
	loop=*(int *)arg;
	printf("thread_2 invoked\n");
	for(i=0;i<=loop;i++)
	{
		pthread_mutex_lock(&mtx);
		local=glob;
		local++;
		glob=local;
		pthread_mutex_unlock(&mtx);
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
