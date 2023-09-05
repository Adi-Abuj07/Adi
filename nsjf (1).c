#include<stdio.h>
void main()
{
 int i,j,temp,btemp,proc[6],at[6],bt[6],wt[6],tt[6],sum=0,n;
 float avrg,avg;
 printf("enter the number of process:");
 scanf("%d",&n);
for(i=0;i<n;i++)
{
 printf("enter the process number:");
 scanf("%d",&proc[i]);
 printf("enter the arrival time:");
 scanf("%d",&at[i]);
 printf("enter the burst time:");
 scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
  for(j=i+1;j<n;j++)
  {
    if(at[i]>at[j])
    {
      temp=at[i];
      at[i]=at[j];
      at[j]=temp;
      btemp=bt[i];
      bt[i]=bt[j];
      bt[j]=btemp;
      temp=proc[i];
      proc[i]=proc[j];
      proc[j]=temp;    
    }
  }
}
for(i=1;i<n;i++)
{
  for(j=i+1;j<n;j++)
  {
    if(bt[i]>bt[j])
    {
      temp=at[i];
      at[i]=at[j];
      at[j]=temp;
      btemp=bt[i];
      bt[i]=bt[j];
      bt[j]=btemp;
      temp=proc[i];
      proc[i]=proc[j];
      proc[j]=temp;    
    }
  }
}
for(i=1;i<n;i++)
{
  if(bt[i]==bt[j])
  {
    if(at[i]>at[j])
    {
      temp=at[i];
      at[i]=at[j];
      at[j]=temp;
      btemp=bt[i];
      bt[i]=bt[j];
      bt[j]=btemp;
      temp=proc[i];
      proc[i]=proc[j];
      proc[j]=temp;    
    }
  }
}
printf("\nafter sorting on arrival time\n");
printf("process\tarrival time\tburst time\n");
for(i=0;i<n;i++)
{
  printf("\np%d\t",proc[i]);
  printf("%d\t",at[i]);
  printf("%d\t",bt[i]);
}
wt[0]=0;
for(i=0;i<n;i++)
{
  wt[i+1]=wt[i]+bt[i];
  sum+=(wt[i]-at[i]);
}
wt[n]=wt[n-1]+bt[n-1];
printf("\nthe waiting time is\t%d",sum);
avrg=(float)sum/(float)n;
printf("\nthe average waiting time is\t%f",avrg);
sum=0;
for(i=0;i<n;i++)
{
 tt[i]=wt[i+1]-at[i];
 sum+=tt[i];
}
printf("\nthe turnarround time is\t%d",sum);
avg=(float)sum/(float)n;
printf("\nthe average turnarround time is\t%f",avg);
printf("\nGANNT CHART\n");
printf("\n----------------------------------------------------------------------------\n");
for(i=0;i<n;i++)
{
 printf("\t|p%d\t",proc[i]);
} 
printf("\n----------------------------------------------------------------------------\n");
for(i=0;i<=n;i++)
{
 printf("%d\t\t\t",wt[i]);
}
}
