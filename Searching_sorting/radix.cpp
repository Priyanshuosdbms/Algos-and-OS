#include<bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort on the specified digit
void countingSort(int arr[], int n, int exp) {
    const int radix = 10; // Base 10 for decimal numbers
    int output[n];
    int count[radix] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % radix]++;
    }

    // Calculate the cumulative count
    for (int i = 1; i < radix; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array using the count array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main Radix Sort function
void radixSort(int arr[], int n) {
    // Find the maximum element to determine the number of digits
    int max = getMax(arr, n);

    // Perform counting sort for every digit, from least significant to most significant
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
} 

int main()
{
    int arr[] = {1000,10242,1023,44};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);

    for(auto element : arr)
    {
        cout << element << " ";
    }

    return 0;
}