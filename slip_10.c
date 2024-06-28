#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

void main()
{
char str[20]="Hello world";
int fd=open("redi.txt",O_WRONLY);

if(fd==-1)
{
printf("error");
}
else
{
close(1);
dup2(fd,1);
printf("data is writen in file");
close(fd);
}

}
