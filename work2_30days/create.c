#include<stdio.h>
#include<fcntl.h>
#include<string.h>
void main()
{
	int res;
	//res=open("sample.txt",O_CREAT,0640);
	res=creat("./sample.txt",0640);
	printf("open file fd val is %d\n",res);
	if(res<0)
		printf("fail to create sample.txt file\n");
	close(res);
	res=open("test.txt",O_RDWR|O_APPEND);
	printf("open file fd val is %d\n",res);
	write(res,"bye bye",strlen("bye bye"));
}
