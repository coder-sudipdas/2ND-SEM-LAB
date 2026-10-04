//Write a C program to simulate the CPU scheduling algorithm First Come First Serve (FCFS).
#include<stdio.h>
#define MAX 20
int main()
{
	int n,i;
	int bt[MAX],wt[MAX],tat[MAX];
	float avg_wt=0,avg_tat=0;
	printf("\nEnter number of processes:\n");
	scanf("%d",&n);
	printf("\nEnter burst time:\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d: ",i+1);
		scanf("%d",&bt[i]);
		
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
	}
	for(i=0;i<n;i++)
	{
		tat[i]=wt[i]+bt[i];
		avg_wt=avg_wt+wt[i];
		avg_tat=avg_tat+tat[i];
	}
	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
	}
	avg_wt=avg_wt/n;
	avg_tat=avg_tat/n;
	printf("\nAverage Waiting Time=%.2f",avg_wt);
	printf("\nAverage Turnaround Time=%.2f",avg_tat);
	return 0;
	
}




