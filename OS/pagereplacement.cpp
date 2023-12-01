#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void lru(int stack[], int array[], int frames, int n)
{
    int i, j, found = 0, page_faults = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < frames; j++)
        {
            if (array[i] == stack[j])
            {
                found = 1;
                break;
            }
            if (found == 0 && j == frames - 1)
            {
                // lru logic
            }
        }
        if (found != 1)
            page_faults++;
    }

    cout << "LRU page faults:" <<page_faults<<endl;
}
/*
void lru(int stack[], int array[], int frames, int n) {
    vector<int> lruStack(frames, -1); // -1 means empty slot
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check if the page is already in the stack
        for (int j = 0; j < frames; j++) {
            if (array[i] == stack[j]) {
                found = true;
                // Move the found page to the most recently used position in lruStack
                for (int k = j; k > 0; k--) {
                    lruStack[k] = lruStack[k - 1];
                }
                lruStack[0] = array[i];
                break;
            }
        }

        if (!found) {
            // Find the least recently used page and replace it
            int lruPage = lruStack[frames - 1];
            for (int j = frames - 1; j > 0; j--) {
                lruStack[j] = lruStack[j - 1];
            }
            lruStack[0] = array[i];

            // Update the main stack and increment page_faults
            for (int j = 0; j < frames; j++) {
                if (stack[j] == lruPage) {
                    stack[j] = array[i];
                    break;
                }
            }
            page_faults++;
        }
    }

    cout << "LRU page faults: " << page_faults << endl;
}
*/
void optimal()
{
}

int main()
{
    int i, j, frames, n, page_faults = 0, z, found = 0;
    printf("Enter number of frames\n");
    scanf("%d", &frames);
    int stack[frames] = {0};
    cout << "Enter the reference string length" << endl;
    cin >> n;

    int array[n];
    j = 0;
    cout << "Enter reference string:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    /*
    for(i=0 ; i<n ; i++)
    {
        for(z = 0 ; z < frames ; z++)
        {
            if(array[i] == stack[z])
            {
                found = 1;
                break;
            }

            if(z == frames-1 && found == 0)
            {
                stack[j] = array[i];
                j = (j + 1) %frames;
            }
        }
        if(found != 1)
        page_faults++;
    }

    cout << "Number of page faults are" <<page_faults <<endl;
    */

    lru(stack, array, frames, n);
}