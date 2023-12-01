#include<bits/stdc++.h>
using  namespace std;

class Solution {
public:
    // Heapify function to maintain the max heap property.
    void heapify(int arr[], int n, int i) {
        int largest = i;  // Initialize the largest as the root
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2;  // Right child

        // If the left child is larger than the root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If the right child is larger than the largest so far
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If the largest is not the root, swap them and recursively heapify the affected subtree.
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Function to build a Max Heap from an array.
    void buildHeap(int arr[], int n) {
        // Start from the last non-leaf node and heapify all nodes in reverse order.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    // Function to perform Heap Sort.
    void heapSort(int arr[], int n) {
        // Build a Max Heap from the input array.
        buildHeap(arr, n);

        // Extract elements from the heap one by one.
        for (int i = n - 1; i >= 0; i--) {
            // Move the current root (maximum element) to the end.
            swap(arr[0], arr[i]);

            // Call heapify on the reduced heap to restore the max heap property.
            heapify(arr, i, 0);
        }
    }
};

int main()
{
    int arr[] = {1,2,3,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    Solution s;
    s.heapSort(arr,n);

    for(auto ele : arr)
    {
        cout << ele << " ";
    }

    return 0;
}