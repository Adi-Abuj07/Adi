#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
struct stat s;

char *filename="Slip_3.c";

if(fstat(open(filename,O_RDONLY),&s)<0)
{
printf("stat error");
}
printf("\nInode no : %ld",s.st_ino);
printf("Hard link  : %d",s.st_mode);
printf(s.st_mode & S_IRUSR?"r":"-");
printf(s.st_mode & S_IWUSR?"w":"-");
printf(s.st_mode & S_IXUSR?"x":"-");

return 0;
}
