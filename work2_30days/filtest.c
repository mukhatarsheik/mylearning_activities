#include<stdio_ext.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char buf[25];
	int fd,f_c,opt;
	fd=open("test.txt",O_RDWR|O_TRUNC);
	printf("fd val is %d\n",fd);
	
	while(1)
	{
		printf("cur is %d and enter the string\n",f_c);
		scanf("%[^\n]s",buf);
		__fpurge(stdin);
		f_c=write(fd,buf,strlen(buf));
		printf("f_cur val is %d and enter 0 for exit\n",f_c);
		scanf("%d",&opt);
		__fpurge(stdin);
		if(opt==0)
			break;
	}
	while(f_c=read(fd,buf,4))
	{
		buf[f_c]='\0';
		printf("the cur val is %d and data is %s\n",f_c,buf);
	}
	printf("ok bro i am done\n");
}
