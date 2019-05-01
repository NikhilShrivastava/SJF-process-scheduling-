/*Consider a scheduling approach which is non pre-emptive similar to shortest job next in nature.
 The priority of each job is dependent on its estimated run time, and also the amount of time it has spent waiting.
  Jobs gain higher priority the longer they wait, which prevents indefinite postponement. 
  The jobs that have spent a long time waiting compete against those estimated to have short run times. The priority can be computed as
Priority = 1+ Waiting time / Estimated run time. Write a program to implement such an algorithm.*/

#include<iostream>
#include<stdio.h>
#include<conio.h>
int main()
{
int i,j,p[10],n, tatt=0, watt=0,total_burst_time=0;
int burst_time[10],temp,arrival_time[10],t,wait_time[10],ct[10],turn_around_time[10],wt[10],ta=0;
int at[10],process[10],bt[10];
float total_tat_time=0,total_wait_time=0;
float priority[10]={0};
printf(" \t\t\t-------------------------Process Scheduling------------------------\n");
printf("\nEnter the No. of processes :");
scanf("%d",&n);

	printf("Enter the process number:");
	for(i=0;i<n;i++)
	scanf("%d",&p[i]);
	printf("Enter the arrival time of the process:");
	for(i=0;i<n;i++)
	scanf("%d",&arrival_time[i]);
	printf("Enter the burst of the processes:");
	for(int i=0;i<n;i++)
	scanf("%d",&burst_time[i]);
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(arrival_time[i]<arrival_time[j])
		{
			temp=p[j];
			p[j]=p[i];
			p[i]=temp;
	
			temp=arrival_time[j];
			arrival_time[j]=arrival_time[i];
			arrival_time[i]=temp;
	
			temp=burst_time[j];	
			burst_time[j]=burst_time[i];
			burst_time[i]=temp;
		}
	}
}


int time=burst_time[0];
for(i=1;i<n;i++)
{  
	if(time>=arrival_time[i])
	{ 
	   at[i]=arrival_time[i];
	    bt[i]=burst_time[i];
	   process[i]=p[i];
	    wt[i]=time-at[i];
	priority[i]=1+(wt[i]/bt[i]);
		
	}
	
}

system("cls");
 	for(i=1;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(priority[i]<priority[j])
			{
				t=burst_time[i];
				burst_time[i]=burst_time[j];
				burst_time[j]=t;
				t=p[i];
				p[i]=p[j];
				p[j]=t;
				t=arrival_time[i];
				arrival_time[i]=arrival_time[j];
				arrival_time[j]=t;
				t=priority[i];
				priority[i]=priority[j];
				priority[j]=t;
				
				
			}
			else if(priority[i]==priority[j])
			{
				if(burst_time[i]>burst_time[j])
				{  t=burst_time[i];
				burst_time[i]=burst_time[j];
				burst_time[j]=t;
				t=p[i];
				p[i]=p[j];
				p[j]=t;
				t=arrival_time[i];
				arrival_time[i]=arrival_time[j];
				arrival_time[j]=t;
				
				t=priority[i];
				priority[i]=priority[j];
				priority[j]=t;
					
				}
			}
		}
	}

 ct[0]=burst_time[0];
 for(i=1;i<n;i++)
 {
 	ct[i]=burst_time[i]+ct[i-1];
 }
for(i=0;i<n;i++)
{
	turn_around_time[i]=ct[i]-arrival_time[i];
	tatt=tatt+turn_around_time[i];
	
}

for(i=0;i<n;i++)
{
	wait_time[i]=turn_around_time[i]-burst_time[i];
	watt=watt+wait_time[i];
}
printf(" \t\t\t-------------------------Process Scheduling------------------------\n\n\n");

printf("\tProcess\t Arrival time\t Burst time\t Waiting time\t Turn Around Time\tPriority\tCompletion Time ");
for(i=0;i<n;i++){                                              
 printf("\n\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%f\t\t%d",p[i],arrival_time[i],burst_time[i],wait_time[i],turn_around_time[i],priority[i],ct[i]);
    } 
    float cc=n;
    float aa;
	aa=tatt/cc;
    float bb;
	bb=watt/cc;
    printf("\nAverage Waiting time=%f",bb);
    printf("\nAverage Turn Around time=%f",aa);         
return 0;

}

