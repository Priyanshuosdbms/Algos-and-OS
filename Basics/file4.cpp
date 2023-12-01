#include<bits/stdc++.h>
using namespace std;

int duplicate(vector<int> arr)
{
    int i;
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr.begin(), arr.end());    
    for(i=0 ; i<n-1 ; i++)
    {
        if(arr[i] == arr[i+1])
        {
            cout << arr[i] << endl;
            break;
        }
    }
    return arr[i];
}

int duplicate_ptr(vector<int> arr)
{
    int i;
    int slow_ptr, fast_ptr;
    slow_ptr = fast_ptr = arr[0];

    do
    {
        slow_ptr = arr[slow_ptr];
        fast_ptr = arr[arr[slow_ptr]];
    }while(slow_ptr != fast_ptr);

    fast_ptr = arr[0];

    while(slow_ptr != fast_ptr)
    {
        slow_ptr = arr[slow_ptr];
        fast_ptr = arr[fast_ptr];
    }

    return slow_ptr;
    
}

int main()
{
    vector<int> arr ;
    arr= {1,2,3,2,4,5,6,7,8,9};
    
    cout << duplicate(arr) <<endl ; 
    cout << duplicate_ptr(arr) <<endl;
    return 0;
}


















/**
 * do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
 * 
 * 
 */