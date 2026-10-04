#include <stdio.h>

int main()
{
    int n, tq;
    int bt[20], rem[20], ct[20], wt[20], tat[20];
    int i, time = 0, done;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    /* Round Robin */
    while(1)
    {
        done = 1;

        for(i = 0; i < n; i++)
        {
            if(rem[i] > 0)
            {
                done = 0;

                if(rem[i] > tq)
                {
                    time = time + tq;
                    rem[i] = rem[i] - tq;
                }
                else
                {
                    time = time + rem[i];
                    rem[i] = 0;
                    ct[i] = time;
                }
            }
        }

        if(done == 1)
            break;
    }

    /* Calculate WT and TAT */
    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i];          // Arrival time = 0
        wt[i] = tat[i] - bt[i];

        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
    }

    printf("\nProcess\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}

