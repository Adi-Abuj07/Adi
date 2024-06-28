#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>


void main()
{
DIR *dir;
struct dirent *entry;
struct stat s;

dir=opendir(".");
if(dir==NULL)
{
printf("error");
}
while((entry=readdir(dir))!=NULL)
{

if(stat(entry->d_name, &s)<0)
{
printf("error");
}
if(S_ISREG(s.st_mode)&& access(entry->d_name,W_OK)==0)
{
printf("File name %s  \n",entry->d_name);
}
}
}
