/*
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<climits>

void prem_priority(int at[] , int bt[] , int pr[] ,int n)
{
    int awat = 0,atat = 0,curr_time;
    int i,j,l,k;
    for(i=0 ; i<n ; i++)
    {
        for(j=i+1 ; j<n ; j++)
        {
            if(pr[i] > pr[j] && at[i] >= at[j])
            {
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                
                int temp1 = at[i];
                at[i] = at[j];
                at[j] = temp1;

                
                int temp2 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp2;
            }
        }
    }    

    curr_time = at[0];

    for(i=0 ; i<n ; i++)
    {
        awat = awat + curr_time;
        atat = atat + bt[i];        
    }
}

void non_priority(int at[] , int bt[] , int n)
{

}

void rr(int at[] , int bt[] ,int n)
{

}


int main()
{
    int at[100],bt[100],tasks;
    int i,j,priority[100];
    printf("Enter number of tasks in ready queue\n");
    scanf("%d",&tasks);
    printf("Enter arrival time and burst times and priority respectively\n");
    for(i=0 ; i<tasks ; i++)
    {
        scanf("%d %d %d",&at[i] , &bt[i] , &priority[i]);
    }
    printf("Arrival time|Burst time|Priority\n");
    for(i=0 ; i<tasks ; i++)
    {
        printf("%d           |   %d         |  %d\n",at[i],bt[i],priority[i]);
    }

    prem_priority(at,bt,priority,tasks);
    non_priority(at,bt,tasks);
    rr(at,bt,tasks);
    
    return 0;
}

*/

#include <stdio.h>

void prem_priority(int at[], int bt[], int pr[], int n) {
    int awat = 0, atat = 0, curr_time = 0;
    int remaining[n]; // To keep track of remaining burst time for each process
    int completed[n]; // To check if a process has completed
    int total_completed = 0; // To keep track of the total number of completed processes

    // Initialize remaining and completed arrays
    for (int i = 0; i < n; i++) {
        remaining[i] = bt[i];
        completed[i] = 0;
    }

    while (total_completed < n) {
        int highest_priority = -1;
        int highest_priority_index = -1;

        // Find the process with the highest priority that has arrived and not completed
        for (int i = 0; i < n; i++) {
            if (at[i] <= curr_time && completed[i] == 0) {
                if (highest_priority == -1 || pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    highest_priority_index = i;
                }
            }
        }

        if (highest_priority_index == -1) {
            curr_time++; // No process available, increment time
        } else {
            // Execute the process with the highest priority for 1 unit of time
            remaining[highest_priority_index]--;
            curr_time++;

            // If the process has completed its execution
            if (remaining[highest_priority_index] == 0) {
                completed[highest_priority_index] = 1;
                total_completed++;

                // Calculate waiting and turnaround time for the completed process
                awat += curr_time - at[highest_priority_index] - bt[highest_priority_index];
                atat += curr_time - at[highest_priority_index];
            }
        }
    }

    // Calculate average waiting and turnaround time
    awat /= n;
    atat /= n;

    // Print the results
    printf("Average Waiting Time: %d\n", awat);
    printf("Average Turnaround Time: %d\n", atat);
}
void non_preemptive_priority(int at[], int bt[], int pr[], int n) {
    int awat = 0, atat = 0, curr_time = 0;
    int completed[n]; // To check if a process has completed
    int total_completed = 0; // To keep track of the total number of completed processes

    // Initialize completed array
    for (int i = 0; i < n; i++) {
        completed[i] = 0;
    }

    while (total_completed < n) {
        int highest_priority = -1;
        int highest_priority_index = -1;

        // Find the process with the highest priority that has arrived and not completed
        for (int i = 0; i < n; i++) {
            if (at[i] <= curr_time && completed[i] == 0) {
                if (highest_priority == -1 || pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    highest_priority_index = i;
                }
            }
        }

        if (highest_priority_index == -1) {
            curr_time++; // No process available, increment time
        } else {
            // Execute the process with the highest priority
            curr_time += bt[highest_priority_index];
            completed[highest_priority_index] = 1;
            total_completed++;

            // Calculate waiting and turnaround time for the completed process
            awat += curr_time - at[highest_priority_index] - bt[highest_priority_index];
            atat += curr_time - at[highest_priority_index];
        }
    }

    // Calculate average waiting and turnaround time
    awat /= n;
    atat /= n;

    // Print the results
    printf("Average Waiting Time: %d\n", awat);
    printf("Average Turnaround Time: %d\n", atat);
}
void preemptive_round_robin(int at[], int bt[], int n, int quantum) {
    int remaining[n]; // To keep track of remaining burst time for each process
    int curr_time = 0;

    // Initialize remaining array
    for (int i = 0; i < n; i++) {
        remaining[i] = bt[i];
    }

    bool done = false;

    while (!done) {
        done = true;

        for (int i = 0; i < n; i++) {
            if (at[i] <= curr_time && remaining[i] > 0) {
                done = false;

                // Execute the process for the quantum or remaining burst time, whichever is smaller
                int execute_time = (remaining[i] < quantum) ? remaining[i] : quantum;
                curr_time += execute_time;
                remaining[i] -= execute_time;

                // If the process has completed its execution
                if (remaining[i] == 0) {
                    printf("Process %d completed at time %d\n", i + 1, curr_time);
                }
            }
        }
    }
}
void non_preemptive_round_robin(int at[], int bt[], int n, int quantum) {
    int remaining[n]; // To keep track of remaining burst time for each process
    int curr_time = 0;

    // Initialize remaining array
    for (int i = 0; i < n; i++) {
        remaining[i] = bt[i];
    }

    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (at[i] <= curr_time && remaining[i] > 0) {
                // Execute the process for the quantum or remaining burst time, whichever is smaller
                int execute_time = (remaining[i] < quantum) ? remaining[i] : quantum;
                curr_time += execute_time;
                remaining[i] -= execute_time;

                if (remaining[i] == 0) {
                    completed++;
                    printf("Process %d completed at time %d\n", i + 1, curr_time);
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n];
    printf("Enter arrival times, burst times, and priorities for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    
    non_preemptive_priority(at,bt,pr,n);
    prem_priority(at, bt, pr, n);
    int tq;
    printf("Enter time quantum :\n");
    scanf("%d",&tq);
    non_preemptive_round_robin(at,bt,n,tq);
    preemptive_round_robin(at,bt,n,tq);

    return 0;
}
