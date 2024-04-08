#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
void main()
{
	struct stat stu,*sptr;
	sptr=&stu;
	int fd,fd1,f_c1,f_c2,res,size_f1,size_f2;
	char buf[40],tbuf[40];
	fd=open("test.txt",O_RDWR);
	printf("test file is open from process %d and fd is %d\n",getpid(),fd);
	fd1=open("sam.txt",O_RDWR);
	printf("sam file is open from process %d and fd is %d\n",getpid(),fd1);
	res=fstat(fd,&stu);
	if(res!=0)
		printf("fstat is fail\n");
	size_f1=sptr->st_size;
	res=fstat(fd,&stu);
	if(res!=0)
		printf("fstat is fail\n");
	size_f2=sptr->st_size;
	f_c1=read(fd,buf,size_f1-1);
	buf[f_c1]='\0';
	res=lseek(fd,-f_c1,SEEK_CUR);
	printf("the res after 1 lseek is %d\n",res);
	f_c2=read(fd1,tbuf,size_f2-1);
	tbuf[f_c2]='\0';
	res=lseek(fd1,-f_c2,SEEK_CUR);
	printf("the res after 1 lseek is %d\n",res);
	f_c1=write(fd,tbuf,strlen(tbuf));
	printf("f_c1 val after write is %d\n",f_c1);
	f_c2=write(fd1,buf,strlen(buf));
	printf("f_c2 val after write is %d\n",f_c2);

}
