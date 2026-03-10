#include <stdio.h>

struct Process
{
    int pid;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
};

int main()
{
    int n, time = 0, completed = 0, minPriority, current = -1;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i+1);

        p[i].pid = i+1;

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Priority: ");
        scanf("%d", &p[i].priority);

        p[i].remaining = p[i].burst;
    }

    while(completed != n)
    {
        minPriority = 9999;
        current = -1;

        for(int i = 0; i < n; i++)
        {
            if(p[i].arrival <= time && p[i].remaining > 0)
            {
                if(p[i].priority < minPriority)
                {
                    minPriority = p[i].priority;
                    current = i;
                }
            }
        }

        if(current == -1)
        {
            time++;
            continue;
        }

        p[current].remaining--;
        time++;

        if(p[current].remaining == 0)
        {
            completed++;

            p[current].completion = time;

            p[current].turnaround = 
                p[current].completion - p[current].arrival;

            p[current].waiting =
                p[current].turnaround - p[current].burst;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,
        p[i].arrival,
        p[i].burst,
        p[i].priority,
        p[i].completion,
        p[i].turnaround,
        p[i].waiting);
    }

    return 0;
}
