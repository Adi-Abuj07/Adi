#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
int fd[2];
pid_t pid;

if(pipe(fd)<0)
{
printf("pipe error");
}

pid=fork();

if(pid<0)
{
printf("error fork");
}
else if(pid>0)
{
close(fd[0]);
dup2(fd[1],STDOUT_FILENO);
execlp("ls","ls","-l",NULL);
close(fd[1]);
}
else{
close(fd[1]);
dup2(fd[0],STDIN_FILENO);
execlp("wc","wc","-l",NULL);
close(fd[0]);
}
return 0;
}
