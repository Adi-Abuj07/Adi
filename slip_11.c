#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *fname[])
{
struct stat s;
for(int i=1;i<argc;i++)
{
if(stat(fname[i],&s)<0)
{
printf("error");
}
else if(S_ISREG(s.st_mode))
{
printf("\n %s is  Regular file",fname[i]);
}
else if(S_ISCHR(s.st_mode))
{
printf("\n %s is character file",fname[i]);
}
else if(S_ISBLK(s.st_mode))
{
printf("\n %s is Block file",fname[i]);
}
else if(S_ISDIR(s.st_mode))
{
printf("\n %s is Divice file ",fname[i]);
}
}
}
