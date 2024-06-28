#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void main()
{
FILE *file1,*file2;
char ch;

file1=fopen("f1.txt","r");

file2=fopen("f2.txt","w");
if(file1<0)
{
printf("error");
}
while((ch=getc(file1))!=EOF)
{
fputc(ch,file2);
}
remove("f1.txt");
rename("f2.txt","f1.txt");

}
