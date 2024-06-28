#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>


void main()
{
DIR *dir;
struct dirent *entry;

dir=opendir(".");
if(dir==NULL)
{
printf("error");
}

while((entry=readdir(dir))!=NULL)
{
if(entry->d_type==DT_DIR && entry->d_name[0]!='.')
{
printf("%s",entry->d_name);
}
}
closedir(dir);
}
