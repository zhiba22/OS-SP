/*
 * Round Robin Scheduling Program in C
 */

#include <stdio.h>

#define MAX 100

int main()
{
    int n;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Too many processes!\n");
        return 1;
    }

    int arr_time[MAX], burst_time[MAX], remaining_time[MAX];
    int wait_time = 0, ta_time = 0;

    // Input process details
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Details of Process %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &arr_time[i]);

        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);

        remaining_time[i] = burst_time[i];
    }

    int time_quantum;
    printf("\nEnter Time Quantum: ");
    scanf("%d", &time_quantum);

    int total = 0;       // current time
    int completed = 0;   // number of finished processes

    printf("\nProcess  Burst Time  Turnaround Time  Waiting Time\n");

    while (completed < n)
    {
        int executed = 0;

        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0 && arr_time[i] <= total)
            {
                executed = 1;

                if (remaining_time[i] > time_quantum)
                {
                    total += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
                else
                {
                    total += remaining_time[i];

                    int turnaround = total - arr_time[i];
                    int waiting = turnaround - burst_time[i];

                    printf("P%-7d %-11d %-16d %d\n",
                           i + 1, burst_time[i], turnaround, waiting);

                    wait_time += waiting;
                    ta_time += turnaround;

                    remaining_time[i] = 0;
                    completed++;
                }
            }
        }

        // If no process executed, increase time
        if (!executed)
            total++;
    }

    printf("\nAverage Waiting Time = %.2f", (float)wait_time / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)ta_time / n);

    return 0;
}