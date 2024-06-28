#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

void main()
{
int fd=open("text1.txt",O_WRONLY | O_CREAT,0777);
if(fd<0)
{
printf("error opening file");
}
write(fd,"Hello",5);

int fd1=dup(fd);
if(fd1<0)
{
printf("error opening file");
}
write(fd1,"Welcome in AGCP",16);
printf("data inserted");
close(fd);
close(fd1);

}
