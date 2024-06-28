#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
char str[]="Hello";
int fd=open("slip_5.txt",O_WRONLY);
char b[10];

write(fd,str,strlen(str));
lseek(fd,95,SEEK_SET);
write(fd,str,strlen(str));

close(fd);

fd=open("slip_5.txt",O_RDONLY);
lseek(fd,0,SEEK_SET);
read(fd,b,5);
printf("%s",b);
close(fd);
return 0;
}
