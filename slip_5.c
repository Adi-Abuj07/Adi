#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>

int main()
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
if(stat(entry->d_name,&s)<0)
{
printf("stat error");
}
printf("Inode No : %ld\n",s.st_ino);
printf("File size  : %ld",s.st_size);
}
closedir(dir);
}
