#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
// 98 183 37 122 14 124 65 67
void fcfs(int head, int queue[], int n)
{
    int seek_time = 0;
    seek_time = abs(head - queue[0]);
    printf("Current seek : %d\n", seek_time);
    for (int i = 0; i < n - 1; i++)
    {
        seek_time += abs(queue[i] - queue[i + 1]);
        printf("Current seek : %d\n", seek_time);
    }

    printf("Final seek is : %d\n", seek_time);
}
/*
void sorted(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
*/
int find_nearest(int head, int queue[], int n, int visited[])
{
    int index = -1;
    int min_seek = 9999; // max
    for (int i = 0; i < n; i++)
    {
        if (visited[i] != -1)
        {
            int seek = abs(head - queue[i]);
            if (seek < min_seek)
            {
                min_seek = seek;
                index = i;
            }
        }
    }

    return index;
}

void sstf(int head, int queue[], int n)
{
    int seek_time = 0;
    int visited[n] = {0};

    for (int i = 0; i < n; i++)
    {
        int nearest_index = find_nearest(head, queue, n, visited);
        if (nearest_index != -1)
        {
            visited[nearest_index] = -1;
            seek_time += abs(head - queue[nearest_index]);
            printf("Current seek : %d\n", seek_time);
            head = queue[nearest_index];
        }
    }

    printf("Total seek time : %d\n", seek_time);
}

void scan(int head, int queue[], int n)
{
    int left[n] = {0}, right[n] = {199};
    int dirc, seek_time = 0, right_size = 0, left_size = 0;
    for (int i = 0; i < n; i++)
    {
        if (head > queue[i])
            left[left_size++] = queue[i];

        else
            right[right_size++] = queue[i];
    }

    for (int i = 0; i < left_size - 1; i++)
    {
        for (int j = 0; j < left_size - i - 1; j++)
        {
            if (left[i] < left[j + 1])
            {
                int temp1 = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp1;
            }
        }
    }

    for (int i = 0; i < right_size - 1; i++)
    {
        for (int j = 0; j < right_size - i - 1; j++)
        {
            if (right[j] > right[j + 1])
            {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    printf("Enter -1 for left and 1 for right \n");
    scanf("%d", &dirc);

    if (dirc == 1)
    {
        seek_time = abs(head - right[0]);
        for (int i = 0; i < right_size-1; i++)
        {
            seek_time += abs(right[i] - right[i+1]);
        }

        seek_time += right[right_size-1];

        for (int i = 0; i < n; i++)
        {
            if (left[i] < 199)
            {
                seek_time += abs(left[i] - left[i + 1]);
            }
        }

        printf("Total seek tim : %d\n", seek_time);
    }

    if (dirc == -1)
    {

        seek_time = abs(head - left[0]);

        for (int i = 0; i < n; i++)
        {
            if (left[i] < 199)
            {
                seek_time += abs(left[i] - left[i + 1]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (right[i] > 0)
            {
                seek_time += abs(right[i] - right[i + 1]);
            }
        }

        printf("Total seek tim : %d\n", seek_time);
    }
}

int main()
{
    int head, i, j, queue_size;
    printf("Enter head position\n");
    scanf("%d", &head);
    printf("Enter queue size:\n");
    scanf("%d", &queue_size);
    int queue[queue_size];
    printf("Enter queue data : \n");
    for (i = 0; i < queue_size; i++)
    {
        scanf("%d", &queue[i]);
    }

    // fcfs(head,queue,queue_size);
    sstf(head, queue, queue_size);
    scan(head, queue, queue_size);
    return 0;
}

/*

// Function to find the index of the nearest unvisited request
int find_nearest(int head, int queue[], int n, int visited[]) {
    int min_seek = INT_MAX;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int seek = abs(head - queue[i]);
            if (seek < min_seek) {
                min_seek = seek;
                index = i;
            }
        }
    }

    return index;
}

void sstf(int head, int queue[], int n) {
    int seek_time = 0;
    int visited[n];

    // Initialize visited array to keep track of visited requests
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int nearest_index = find_nearest(head, queue, n, visited);
        if (nearest_index != -1) {
            visited[nearest_index] = 1;
            seek_time += abs(head - queue[nearest_index]);
            printf("Current seek: %d\n", seek_time);
            head = queue[nearest_index];
        }
    }

    printf("Total seek is: %d\n", seek_time);
}






void scan(int head, int queue[], int n) {
    int left[n] = {0}, right[n] = {199}; // Initialize left and right arrays
    int dirc, seek_time = 0, right_size = 0, left_size = 0;

    // Divide the requests into left and right sub-queues based on head position
    for (int i = 0; i < n; i++) {
        if (head > queue[i]) {
            left[left_size++] = queue[i];
        } else {
            right[right_size++] = queue[i];
        }
    }

    // Sort the left and right sub-queues
    for (int i = 0; i < left_size - 1; i++) {
        for (int j = 0; j < left_size - i - 1; j++) {
            if (left[j] < left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < right_size - 1; i++) {
        for (int j = 0; j < right_size - i - 1; j++) {
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    printf("Enter -1 for left and 1 for right: ");
    scanf("%d", &dirc);

    if (dirc == 1) {
        // Moving towards the right
        seek_time = abs(head - right[0]);
        for (int i = 0; i < right_size - 1; i++) {
            seek_time += abs(right[i] - right[i + 1]);
        }

        seek_time += right[right_size - 1]; // Reach the rightmost end

        if (left_size > 0) {
            seek_time += right[right_size - 1] + left[0]; // Seek to leftmost request from right end
            for (int i = 0; i < left_size - 1; i++) {
                seek_time += abs(left[i] - left[i + 1]);
            }
        }

        printf("Total seek time: %d\n", seek_time);
    }

    if (dirc == -1) {
        // Moving towards the left
        seek_time = abs(head - left[0]);
        for (int i = 0; i < left_size - 1; i++) {
            seek_time += abs(left[i] - left[i + 1]);
        }

        seek_time += left[left_size - 1]; // Reach the leftmost end

        if (right_size > 0) {
            seek_time += left[left_size - 1] + right[0]; // Seek to rightmost request from left end
            for (int i = 0; i < right_size - 1; i++) {
                seek_time += abs(right[i] - right[i + 1]);
            }
        }

        printf("Total seek time: %d\n", seek_time);
    }
}

*/