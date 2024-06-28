#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
pid_t pid;
int fd[2];
char str[]="Hello",str1[20];
if(pipe(fd))
{
printf("pipe error");
}
pid=fork();
if(pid<0)
{
printf("process error");
}
else if(pid==0)
{
close(fd[0]);
write(fd[1],str,strlen(str));
printf("parent process write");

}
else
{
close(fd[1]);
printf("child process reading data\n");
read(fd[0],str1,strlen(str1));
printf("\n data = %s \n",str1);
}
}

