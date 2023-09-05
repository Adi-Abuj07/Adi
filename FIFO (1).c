#include<stdio.h>
int num,fs;
int RefString[20],PT[3];

void accept()
{
          int i;
          printf("Enter total Reference String:\n");
          scanf("%d",&num);
          printf("Enter frame size\n");
          scanf("%d",&fs);
          printf("Enter Refrence String:\n");
          for(i=0;i<num;i++)
         {
                 printf("(%d)=",i);
                 scanf("%d",&RefString[i]);
         }
}

int Search(int s)
{
      int i;
      for(i=0;i<fs;i++)
                if(PT[i]==s)
                     return (i);
      return(-1);
}

void FIFO()
{
      int i,j,k=0,Faults=0;
      for(i=0;i<num;i++)
      {
          //gotoxy(4*i+1,2);
             printf("%2d",RefString[i]);
             if(Search(RefString[i])==-1)
             {
                    PT[k]=RefString[i];
                    for(j=0;j<fs;j++)
                    {
                           if(PT[j])
                           {
                                  printf("%2d",PT[j]);
                           }
                    }
                    printf("\n");
                    Faults++;
                    k=(k+1)%fs;
             }
             printf("\n");
             
      }
      printf("total page faults:%d",Faults);
}
    int main()
    {
          
          accept();
          FIFO();
          return 0;
    }

