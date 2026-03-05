/*
 * FCFS Scheduling Program in C
 */

#include <stdio.h>

#define MAX 100

int main()
{
    int pid[MAX];
    int bt[MAX];
    int wt[MAX];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Too many processes!\n");
        return 1;
    }

    printf("Enter process ID of all the processes:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }

    printf("Enter burst time of all the processes:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    // First process waiting time is 0
    wt[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    printf("\nProcess ID   Burst Time   Waiting Time   Turnaround Time\n");

    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        int tat = bt[i] + wt[i];

        printf("%-12d %-12d %-14d %d\n",
               pid[i], bt[i], wt[i], tat);

        total_wt += wt[i];
        total_tat += tat;
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}