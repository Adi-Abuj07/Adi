#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char *arg[])
{
	DIR *dir;
	struct dirent *entry;
	
	dir=opendir(".");
	
	long fsize=atoi(arg[1]);
	printf("%ld",fsize);
	while((entry=readdir(dir))!=NULL)
	{

		struct stat s;
		stat(entry->d_name,&s);
		

			if((S_ISREG(s.st_mode)) && s.st_size > fsize)
			{
				printf("file name %s \n",entry->d_name);
			}
		
	}
	closedir(dir);
}
