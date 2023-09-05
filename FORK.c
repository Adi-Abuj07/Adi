#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int pid=fork();
	if(pid==0)
	{
		printf("I am Child proccess\n");
		printf("Child ID:%d\n\n",getpid());
	}
	else if(pid>0)
	{
		printf("I am parent proccess\n");
		printf("parent ID:%d\n\n",getpid());
	}
	else 
		printf("I am faild to create child proceess!");
	return 0;
}
