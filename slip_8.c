#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

long get_file_size(const char *fname)
{

	struct stat st;
	
	if(stat(fname,&st)==0)
	{
		return st.st_size;
	}
	else
	{
		return -1;
	}
}

int main(int argc,char *argv[])
{
	if(argc<2)
	{
	printf("Error");
	return 1;
	}
	
	int num_file=argc-1;
	char **fname=argv+1;
	long file_size[num_file];
	
	for(int i=0;i<num_file;i++)
	{
	
	file_size[i]=get_file_size(fname[i]);
	if(file_size[i]==-1)
	{
		printf("%s is not valid file name",fname[i]);
		return 1;
	}
	}
	
	for(int i=0;i<num_file-1;i++)
	{
	for(int j=i+1;j<num_file;j++)
	{
		if(file_size[i]>file_size[j])
		{
			long temp_size=file_size[i];
			file_size[i]=file_size[j];
			file_size[j]=temp_size;
			
			char *temp_name=fname[i];
			fname[i]=fname[j];
			fname[j]=temp_name;
		}
	}
	}
	
	printf("\n file sorted by size\n");
	
	for(int i=0;i<num_file;i++)
	{
		printf("%s : %ld bytes\n",fname[i],file_size[i]);
	}
	return 0;
}
