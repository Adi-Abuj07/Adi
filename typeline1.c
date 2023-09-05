#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[]);
int count_lines(char *fname);
int print_all_lines(char *fname);
int print_top_lines(char *fname,int cnt);
int print_bottom_lines(char *fname,int cnt,int tot_lines);
int tot_lines,cnt,curr_cnt;
void main(int argc,char *argv[])
{
char *ptr;
if(argc !=4)
{
                printf("\nInvalid number of arguments\n");
}
if(*argv[2] == '+'|| *argv[2] == '-')
{
tot_lines = count_lines(argv[3]);
ptr = argv[2];
ptr++;
cnt = atoi(ptr);
if(cnt > tot_lines)
{
printf("\nInvalid line count\n");
}
}
if(*argv[2] =='+')
print_top_lines(argv[3],cnt );
else
if(*argv[2] =='-')
print_bottom_lines(argv[3],cnt,tot_lines);
else
print_all_lines(argv[3]);
}
 int count_lines(char *fname)
    {
               int tot_lines,ch;
               FILE *fp;
               fp = fopen(fname,"r");
               if( fp == NULL)
               {
                        printf("\n unable to open file ");
                        return(-1);
               }
                tot_lines = 0;
                ch = fgetc(fp);
                while(ch != EOF)
              {
                      if( ch == 10) // new line
                                   tot_lines++;
                           ch = fgetc(fp);
             }
               //   tot_lines++;
                  fclose(fp);
                  return(tot_lines);
   } // count lines 
   
   
   int print_all_lines(char *fname)
   {
                   int ch;
                   FILE *fp;
                   
                   fp= fopen(fname,"r");
                     
                    ch = fgetc(fp);
                    while( ch != EOF)
                    {
                             printf("%c",ch);
                             ch = fgetc(fp);
                    }
                     fclose(fp);
                                     
   } // print  all lines
    
    int print_top_lines(char  *fname, int cnt)
  {
  
          int ch;
          FILE *fp;
          
          int curr_cnt = 0;
          
          fp = fopen(fname, "r");
          
           ch = fgetc(fp);
           while( curr_cnt < cnt)
                         {printf("%c",ch);
                         if( ch == 10)
                                  {curr_cnt++;
                                  }
                           ch = fgetc(fp);
                   }
                      fclose(fp);
                      
                      
   }
    int print_bottom_lines(char *fname, int cnt , int tot_lines)
 {
         int curr_cnt;
         int ch;
         FILE *fp;
         curr_cnt = 0;
         fp = fopen(fname, "r");
         ch = fgetc(fp);
         while(1) 
         {
                     if(ch  == 10)
                                 curr_cnt++;
                      if( curr_cnt  >=  tot_lines  -  cnt)
                                       break;
                              ch = fgetc(fp);
         }
  
             ch = fgetc(fp);
             while( ch != EOF)
          { 
                        printf("%c", ch);
                        ch = fgetc(fp);
           }
               fclose(fp);
    
}                                                                                                                                            
                         
               
                                                                                                              
