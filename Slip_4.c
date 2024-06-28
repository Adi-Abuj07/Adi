#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

#define SIZE 256

int main()
{
int fd[2];
pid_t pid;

if(pipe(fd)<0)
{
printf("error");
}
pid=fork();

if(pid==0)
{
close(fd[0]);
char *msg[]={"Hello","sppu"};

for(int i=0;i<2;i++)
{
write(fd[1],msg[i],SIZE);
}
close(fd[1]);
}
else
{
close(fd[1]);
char msg[SIZE];
while(read(fd[0],msg,SIZE)>0){

printf("%s  ",msg);
}
close(fd[0]);
}
return 0;
}
