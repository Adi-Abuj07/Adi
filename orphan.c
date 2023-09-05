#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
	int pid;
	pid=getpid();
	printf("Current proccess ID id : %d\n",pid);
	printf("\n[forking child process ....]\n");
	pid=fork();
	if(pid<0)
	{
		printf("process cnnot be created");
	}
	else
	{
		if(pid==0)
		{
			printf("\nchild process is sleeping ...");
			sleep(5);
			printf("orphan child's parent ID : %d",getpid());
		}
		else
		{
			printf("\n parent process completed ..");
		}
	}
	return 0;
}
