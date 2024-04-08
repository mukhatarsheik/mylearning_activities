#include<fcntl.h>
void main()
{
	open("test.txt",O_TRUNC);
	printf("done\n");
}
