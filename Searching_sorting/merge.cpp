//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int i,j,k;
         // Your code here
        int n1 = m - l + 1;
        int n2 = r - m;
        
        int left_arr[n1],right_arr[n2];
        
        for(i=0 ; i<n1 ; i++)
        {
            left_arr[i] = arr[l+i];
        }
        
        for(i=0 ; i<n2 ; i++)
        {
            right_arr[i] = arr[m+i+1];//1 more than mid element
        }
        
        i=0;
        j=0;
        k=l;
        
        while(i<n1 && j<n2)
        {
            if(left_arr[i] <= right_arr[j])
            arr[k++] = left_arr[i++];
            
            else
            arr[k++] = right_arr[j++];
        }
        
        while(i<n1)
        {
            arr[k++] = left_arr[i++];
        }
        
        while(j<n2)
        {
            arr[k++] = right_arr[j++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l < r)
        {
            int m = (l+r-1)/2;
            
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            
            merge(arr,l,m,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}