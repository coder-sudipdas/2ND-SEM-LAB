//Write a C program to simulate the CPU scheduling algorithm Shortest Job First(Non-Preemption).
#include <stdio.h>
int main()
{
 int n, i, j;
 int bt[20], wt[20], tat[20], ct[20], p[20];
 int temp;
 float avg_wt = 0, avg_tat = 0;
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 // Input burst time
 printf("Enter burst time for each process:\n");
 for (i = 0; i < n; i++)
 {
 p[i] = i + 1;
 printf("P%d: ", i + 1);
 scanf("%d", &bt[i]);
 }
 // Sort processes according to burst time
 for (i = 0; i < n - 1; i++)
 {
 for (j = i + 1; j < n; j++)
 {
 if (bt[i] > bt[j])
 {
// Swap burst time
 temp = bt[i];
 bt[i] = bt[j];
 bt[j] = temp;
 // Swap process number
 temp = p[i];
 p[i] = p[j];
 p[j] = temp;
 }
 }
 }
 // Completion time
 ct[0] = bt[0];
 for (i = 1; i < n; i++)
 {
 ct[i] = ct[i - 1] + bt[i];
 }
 // Waiting time and Turnaround time
 for (i = 0; i < n; i++)
 {
 wt[i] = ct[i] - bt[i];
 tat[i] = ct[i];
 avg_wt += wt[i];
 avg_tat += tat[i];
 }
 // Display result
 printf("\nProcess\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
 for (i = 0; i < n; i++)
 {
 printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
 p[i], bt[i], ct[i], wt[i], tat[i]);
 }
 avg_wt = avg_wt / n;
 avg_tat = avg_tat / n;
 printf("\nAverage Waiting Time = %.2f", avg_wt);
 printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
 return 0;
}
