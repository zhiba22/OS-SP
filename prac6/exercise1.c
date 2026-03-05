/*
 * Exercise01.c
 * Non-Preemptive Priority Scheduling
 */

#include <stdio.h>

#define MAX 100   // Maximum number of processes

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;

    // 1. Enter total number of processes
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Number of processes exceeds limit!\n");
        return 1;
    }

    int b[MAX], p[MAX], index[MAX];

    // 2. Enter burst time and priority
    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority for Process P%d: ", i + 1);
        scanf("%d %d", &b[i], &p[i]);
        index[i] = i + 1;
    }

    // 3 & 4. Sort processes by priority (smaller number = higher priority)
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;

        for (int j = i + 1; j < n; j++)
        {
            if (p[j] < p[pos])
            {
                pos = j;
            }
        }

        swap(&p[i], &p[pos]);
        swap(&b[i], &b[pos]);
        swap(&index[i], &index[pos]);
    }

    // 5. Print execution order with timestamps
    int T = 0;

    printf("\nOrder of Process Execution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d executes from %d to %d\n", index[i], T, T + b[i]);
        T += b[i];
    }

    // 6. Calculate waiting time and turnaround time
    printf("\nProcess  Burst Time  Waiting Time  Turnaround Time\n");

    int waiting_time = 0;
    int total_wait = 0, total_turnaround = 0;

    for (int i = 0; i < n; i++)
    {
        int turnaround_time = waiting_time + b[i];

        printf("P%-7d %-11d %-13d %d\n",
               index[i], b[i], waiting_time, turnaround_time);

        total_wait += waiting_time;
        total_turnaround += turnaround_time;

        waiting_time += b[i];
    }

    printf("\nAverage Waiting Time = %.2f",
           (float)total_wait / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           (float)total_turnaround / n);

    return 0;
}