#include<stdio.h>
#include<unistd.h>
void main()
{
	fork();
	fork();
	fork();
	fork();
	printf("hello frd\n");
}
