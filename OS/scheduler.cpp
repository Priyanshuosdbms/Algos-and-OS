
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
class fcfs
{
private:
    int at[100], bt[100], ncs, i, j;
    int num_tasks, curr_time = 0;
    float awat, atat;

public:
    fcfs()
    {
        cout << "Enter number of tasks:" << endl;
        cin >> num_tasks;
        cout << "Enter arrival time and burst times of the tasks" << endl;
        for (i = 0; i < num_tasks; i++)
        {
            cin >> at[i] >> bt[i];
        }
    }

    void output()
    {
        curr_time = at[0];
        awat = atat = 0.0;

        for (i = 0; i < num_tasks; i++)
        {
            if (curr_time < at[i])
            {
                curr_time = at[i]; // Move the current time to the task's arrival time
            }

            awat += curr_time - at[i];         // Calculate waiting time
            atat += curr_time - at[i] + bt[i]; // Calculate turnaround time
            curr_time += bt[i];                // Update current time to account for the task's execution time
        }

        awat = awat / num_tasks;
        atat = atat / num_tasks;

        cout << "AWAT = " << (awat) << endl;
        cout << "ATAT = " << atat << endl;
    }
};

class sjf
{
private:
    int at[100], bt[100], ncs, i, j;
    int num_tasks, curr_time = 0;
    float awat, atat;

public:
    sjf()
    {
        cout << "Enter number of tasks:" << endl;
        cin >> num_tasks;
        cout << "Enter arrival time and burst times of the tasks" << endl;
        for (i = 0; i < num_tasks; i++)
        {
            cin >> at[i] >> bt[i];
        }
    }

    void shortfirst()
    {
        for (i = 0; i < num_tasks; i++)
        {
            for (j = i + 1; j < num_tasks; j++)
            {
                if (at[i] > at[j])
                {
                    swap(at[i], at[j]);
                    swap(bt[i], bt[j]);
                }
            }
        }
    }

    void output()
    {
        curr_time = at[0];
        awat = atat = 0.0;

        for (i = 0; i < num_tasks; i++)
        {
            if (curr_time < at[i])
            {
                curr_time = at[i]; // Move the current time to the task's arrival time
            }

            awat += curr_time - at[i];         // Calculate waiting time
            atat += curr_time - at[i] + bt[i]; // Calculate turnaround time
            curr_time += bt[i];                // Update current time to account for the task's execution time
        }

        awat = awat / num_tasks;
        atat = atat / num_tasks;

        cout << "AWAT = " << (awat) << endl;
        cout << "ATAT = " << atat << endl;
    }
};

class priority
{
private:
    int at[100], bt[100], prior[100], i, j; // Add priority array
    int num_tasks, curr_time = 0;
    float awat, atat;

public:
    priority()
    {
        cout << "Enter number of tasks:" << endl;
        cin >> num_tasks;
        cout << "Enter arrival time, burst times, and priority of the tasks" << endl;
        for (int i = 0; i < num_tasks; i++)
        {
            cin >> at[i] >> bt[i] >> prior[i];
        }
    }

    void priorityScheduling()
    {
        // Implement Priority Scheduling logic here
        for (i = 0; i < num_tasks; i++)
        {
            for (j = i + 1; j < num_tasks; j++)
            {
                if (prior[i] > prior[j])
                {
                    swap(prior[i], prior[j]);
                    swap(at[i], at[j]);
                    swap(bt[i], bt[j]);
                }
            }
        }

        for (i = 0; i < num_tasks; i++)
        {
            if (curr_time < at[i])
            {
                curr_time = at[i]; // Move the current time to the task's arrival time
            }

            awat += curr_time - at[i];         // Calculate waiting time
            atat += curr_time - at[i] + bt[i]; // Calculate turnaround time
            curr_time += bt[i];                // Update current time to account for the task's execution time
        }

        awat = awat / num_tasks;
        atat = atat / num_tasks;
    }

    void output()
    {
        priorityScheduling(); // Call priority scheduling function

        cout << "AWAT = " << awat << endl;
        cout << "ATAT = " << atat << endl;
    }
};

class rr
{
private:
    int at[100], bt[100], ncs, i, j;
    int num_tasks, curr_time = 0, time_quantum, d[100];
    float awat = 0, atat = 0;

public:
    rr()
    {
        cout << "Enter number of tasks:" << endl;
        cin >> num_tasks;
        cout << "Enter time quantum" << endl;
        cin >> time_quantum;
        cout << "Enter arrival time and burst times of the tasks" << endl;
        for (i = 0; i < num_tasks; i++)
        {
            cin >> at[i] >> bt[i];
            d[i] = 0;
        }
        curr_time = at[0];
    }


    void round()
    {
        int remaining_time[num_tasks]; // Array to keep track of remaining burst time

        for (i = 0; i < num_tasks; i++)
        {
            remaining_time[i] = bt[i]; // Initialize remaining burst time
        }

        while (true)
        {
            bool all_tasks_completed = true;

            for (i = 0; i < num_tasks; i++)
            {
                if (remaining_time[i] > 0)
                {
                    all_tasks_completed = false;

                    if (remaining_time[i] <= time_quantum)
                    {
                        awat += curr_time - at[i];                     // Waiting time is calculated when task starts
                        atat += curr_time - at[i] + remaining_time[i]; // Turnaround time is calculated when task completes
                        curr_time += remaining_time[i];
                        remaining_time[i] = 0;
                    }
                    else
                    {
                        awat += curr_time - at[i]; // Waiting time is calculated when task starts
                        curr_time += time_quantum;
                        remaining_time[i] -= time_quantum;
                    }
                }
            }

            if (all_tasks_completed)
            {
                break; // All tasks are completed, exit the loop
            }
        }
    }

    void output()
    {
        round();

        awat /= num_tasks;
        atat /= num_tasks;
        cout << "AWAT = " << awat << endl;
        cout << "ATAT = " << atat << endl;
    }
};

int main()
{
    fcfs a;
    a.output();

    sjf b;
    b.shortfirst();
    b.output();

    priority c;
    c.output();

    rr d;
    d.output();

    return 0;
}
*/

class Task {
public:
    int arrival_time;
    int burst_time;
    int priority;

    // Constructor for initializing Task
    Task(int at, int bt, int prio) : arrival_time(at), burst_time(bt), priority(prio) {}

    // Overload the < operator to compare tasks based on priority
    bool operator<(const Task &other) const {
        return priority > other.priority; // Higher priority tasks have lower priority values
    }
};

int main() {
    int num_tasks;
    cout << "Enter number of tasks: ";
    cin >> num_tasks;

    priority_queue<Task> tasks;

    cout << "Enter arrival time, burst times, and priorities of the tasks:" << endl;
    for (int i = 0; i < num_tasks; i++) {
        int at, bt, prio;
        cin >> at >> bt >> prio;
        tasks.push(Task(at, bt, prio));
    }

    int curr_time = 0;
    float awat = 0, atat = 0;

    while (!tasks.empty()) {
        Task current_task = tasks.top();
        tasks.pop();

        if (curr_time < current_task.arrival_time) {
            curr_time = current_task.arrival_time;
        }

        awat += curr_time - current_task.arrival_time;
        atat += curr_time - current_task.arrival_time + current_task.burst_time;
        curr_time += current_task.burst_time;
    }

    awat /= num_tasks;
    atat /= num_tasks;

    cout << "AWAT = " << awat << endl;
    cout << "ATAT = " << atat << endl;

    return 0;
}
