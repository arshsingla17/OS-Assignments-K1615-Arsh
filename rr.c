#include<stdio.h>
 //Author: Arsh Singla
int main() 
{ 
 
  int i,j,n,t=0,time_quantum,time_quantum1,temp; 
  int wait_time=0,turnaround_time=0,arrival_time[10],burst_time[10],remaining_time[10],tt[10],waiting_time[10],process_id[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  
  // INPUT OF ARRIVAL TIME AND BURST TIME OF EACH PROCESS TAKEN
  
  for(i=0;i<n;i++) 
  { 
  	process_id[i]=i+1;
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",process_id[i]); 
    scanf("%d%d",&arrival_time[i],&burst_time[i]);  
    remaining_time[i]=burst_time[i]; 
  } 
  
  // INPUT TAKEN OF TIME QUANTUMS
  
  printf("Enter Time Quantum 1:\t"); 
  scanf("%d",&time_quantum); 
  printf("Enter Time Quantum 2:\t"); 
  scanf("%d",&time_quantum1);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(i=0;i<n;++i)
  {
  	remaining_time[i]=remaining_time[i]-time_quantum;
  	t=t+6;
  	printf("Remaining time after 6 time quantum of %d=%d\n",process_id[i],remaining_time[i]);
   } 
   for(i=0;i<n;++i)
	{
  	remaining_time[i]=remaining_time[i]-time_quantum1;
  	t=t+10;
  	printf("\nRemaining time after 10 time quantum of %d=%d",process_id[i],remaining_time[i]);
    } 
    
    
    //SORTING OF PROCESSES IN DECREASING ORDER
    
    
    
   for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(remaining_time[i]>remaining_time[j])
			{
				temp=remaining_time[j];
				remaining_time[j]=remaining_time[i];
				remaining_time[i]=temp;
				temp=arrival_time[j];
				arrival_time[j]=arrival_time[i];
				arrival_time[i]=temp;
				temp=burst_time[j];
				burst_time[j]=burst_time[i];
				burst_time[i]=temp;
				temp=process_id[j];
				process_id[j]=process_id[i];
				process_id[i]=temp;
			}
		}	
	}
	
	
	// FINDING WAITING TIME AND TURN AROUNd TIME
	
	for(i=0;i<n;++i)
	{	
	t=t+remaining_time[i];
	tt[i]=t-arrival_time[i];
	waiting_time[i]=tt[i]-burst_time[i];
	wait_time+=waiting_time[i];
	turnaround_time+=tt[i];
	}
	
	
	//PRINTING AVERAGE TURNAROUND TIME AND WAITING TIME
	
	
	printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  	printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
}
