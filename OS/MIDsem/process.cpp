#include <iostream>
using namespace std;
class fcfs
{
public:
    int ready_queue, i, j, k, arr_time[100], burst_time[100];
    fcfs()
    {
        cout << "Enter number of processes in the ready queue";
        cin >> ready_queue;
        cout << "Enter process arrival and burst times" << endl;
        for (i = 0; i < ready_queue; i++)
        {
            cin >> arr_time[i] >> burst_time[i];
        }
    }

    void output()
    {
        int awat = 0, atat = burst_time[0] - arr_time[0], curr_time = arr_time[0];
        cout << "Processing the requests" << endl;
        for (i = 0; i < ready_queue; i++)
        {
            if(curr_time >= arr_time[i])
            {
                atat += 
            }
            else{

            }
        }
    }
};

class sjf
{
public:
    int ready_queue, i, j, k, arr_time, burst_time;
};

class priority
{
public:
    int ready_queue, i, j, k, arr_time, burst_time;
};

class round
{
public:
    int ready_queue, i, j, k, arr_time, burst_time;
};

int main()
{
}