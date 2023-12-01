#include <iostream>
using namespace std;
// 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2
// 4
// 1, 2, 1, 0, 3, 0, 4, 2, 4
// 3
//  4, 7, 6, 1, 7, 6, 1, 2, 7, 2
// 3
int fifo(int ref_size, int arr[], int page_frame)
{
    int i, j, z = 0, page_fault = 0, stack[page_frame];
    stack[page_frame] = {-1};
    for (i = 0; i < ref_size; i++)
    {
        for (j = 0; j < page_frame; j++)
        {
            if (arr[i] == stack[j])
            {
                break;
            }

            else if (j == page_frame - 1 && arr[i] != stack[j])
            {
                stack[z] = arr[i];
                page_fault++;
                z = (z + 1) % page_frame;
            }
        }
    }
    return page_fault;
}

int lru(int ref_size, int arr[], int page_frame)
{
    int i, j, k, rem;
    int page_fault = 0;
    int stack[page_frame][2];

    for (i = 0; i < page_frame; i++)
    {
        stack[i][0] = -1; // Initializing stack entries to an invalid value
        stack[i][1] = 0;
    }

    for (i = 0; i < ref_size; i++)
    {
        int found = 0;

        // Check if the page is already in the stack
        for (j = 0; j < page_frame; j++)
        {
            if (arr[i] == stack[j][0])
            {
                stack[j][1]++; // Increase reference count
                found = 1;
                break;
            }
        }

        // If the page is not found in the stack
        if (!found)
        {
            int minCountIndex = 0;

            // Find the page with the minimum reference count
            for (k = 1; k < page_frame; k++)
            {
                if (stack[k][1] < stack[minCountIndex][1])
                {
                    minCountIndex = k;
                }
            }

            // Replace the page with the minimum reference count
            stack[minCountIndex][0] = arr[i];
            stack[minCountIndex][1] = 1; // Reset reference count
            page_fault++;
        }
    }

    return page_fault;
}

int lru1(int ref_size, int arr[], int page_frame)
{
    int i, j, z = 0, k, l, rem;
    int page_fault = 0, stack[page_frame][2];
    for (i = 0; i < page_frame; i++)
    {
        for (j = 0; j < 2; j++)
        {
            stack[i][j] = 0;
        }
    }
    for (i = 0; i < ref_size; i++)
    {
        for (j = 0; j < page_frame; j++)
        {
            if (arr[i] == stack[j][0])
            {
                stack[j][1] = stack[j][1] + 1;
                break;
            }

            else if (j == page_frame - 1 && arr[i] != stack[j][0])
            {
                // stack[z] = arr[i];
                rem = stack[0][1];
                for (k = 1; k < page_frame; k++)
                {
                    if (stack[k][1] > stack[0][1])
                        rem = k;
                }
                stack[k][0] = arr[i];
                page_fault++;
            }
        }
    }
    return page_fault;
}

int optimal(int ref_size, int arr[], int page_frame) {
    int i, j, k, l;
    int page_fault = 0;
    int stack[page_frame][2];

    for (i = 0; i < page_frame; i++) {
        stack[i][0] = -1;
        stack[i][1] = 0;
    }

    for (i = 0; i < ref_size; i++) {
        int found = 0;

        for (j = 0; j < page_frame; j++) {
            if (arr[i] == stack[j][0]) {
                stack[j][1]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            int mincost[page_frame] = {0};

            for (k = 0; k < page_frame; k++) {
                for (l = i + 1; l < ref_size; l++) {
                    if (stack[k][0] == arr[l]) {
                        mincost[k]++;
                        break;
                    } else {
                        mincost[k]++;
                    }
                }
            }

            int max = mincost[0];
            int maxIndex = 0;

            for (int m = 1; m < page_frame; m++) {
                if (max < mincost[m]) {
                    max = mincost[m];
                    maxIndex = m;
                }
            }

            // Replace the page with the highest cost
            stack[maxIndex][0] = arr[i];
            stack[maxIndex][1] = 1;
            page_fault++;
        }
    }
    return page_fault;
}

int findOptimalReplacement(int arr[], int pageList[], int page_frame, int startIdx, int ref_size)
{
    int maxDistance = -1;
    int optimalIndex = -1;

    for (int i = 0; i < page_frame; i++)
    {
        int found = 0;
        for (int j = startIdx + 1; j < ref_size; j++)
        {
            if (pageList[i] == arr[j])
            {
                found = 1;
                if (j > maxDistance)
                {
                    maxDistance = j;
                    optimalIndex = i;
                }
                break;
            }
        }

        if (!found)
        {
            return i;
        }
    }

    return optimalIndex;
}
int optimal1(int ref_size, int arr[], int page_frame)
{
    int page_fault = 0;
    int pageList[page_frame];

    for (int i = 0; i < page_frame; i++)
    {
        pageList[i] = -1;
    }

    for (int i = 0; i < ref_size; i++)
    {
        int found = 0;

        for (int j = 0; j < page_frame; j++)
        {
            if (pageList[j] == arr[i])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            if (page_fault < page_frame)
            {
                pageList[page_fault] = arr[i];
            }
            else
            {
                int replaceIndex = findOptimalReplacement(arr, pageList, page_frame, i, ref_size);
                pageList[replaceIndex] = arr[i];
            }
            page_fault++;
        }
    }

    return page_fault;
}

int main()
{
    int i, page_frame = 3, size_ref = 12;
    int ref_string[size_ref] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    /*
    cout << "Enter size of reference string:" << endl;
    cin >> size_ref;
    cout << "Enter page frame size: " << endl;
    cin >> page_frame;
    int ref_string[size_ref];
    cout << "Enter referance sring: " << endl;
    for (i = 0; i < size_ref; i++)
    {
        cin >> ref_string[i];
    }
    */
    // cout << "\nPage fault " << fifo(size_ref, ref_string, page_frame);
    // cout << "\nPage fault " << lru(size_ref, ref_string, page_frame);
    cout << "\n Page fault : " << optimal(size_ref, ref_string, page_frame);
    return 0;
}