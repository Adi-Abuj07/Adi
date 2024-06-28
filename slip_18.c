#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main()
{
char b[100 ];
int fd=open("data1.txt",O_WRONLY | O_CREAT,0777);
write(fd,"Hello",5);
lseek(fd,7,SEEK_SET);
write(fd,"Welcome",7);
close(fd);
int fd1=open("data1.txt",O_RDONLY);
lseek(fd1,0,SEEK_SET);
read(fd1,b,5);
printf("\n %s ",b);
lseek(fd1,10,SEEK_SET);
read(fd1,b,20);
printf("\n %s\n",b);
close(fd1);
}  
