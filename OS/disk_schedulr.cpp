#include<iostream>
using namespace std;

int main()
{
    //fcfs
    //sjf
    //scan

    //head pointer
    //random string
    int i,j,head,ref_str,seek_count=0;
    cout << "Enter head value"<<endl;
    //cin >> head;
    head = 50;
    cout<<"Enter ref string value"<<endl;
    //cin>>ref_str;
    ref_str = 8;
    int arr[ref_str] = {176, 79, 34, 60, 92, 11, 41, 114};
/*
    cout << "Enter reference string values"<<endl;
    for(i=0 ; i<ref_str ; i++)
    {
        cin >> arr[i];
    }
*/
    seek_count = abs(head - arr[0]) ;
    cout << "Current seek is : " << seek_count<<endl;
    for(i=1 ; i<ref_str ; i++)
    {
        seek_count += abs(arr[i-1] - arr[i]);        
        cout << "Current seek is : " << seek_count <<endl;
    }

    cout << "Seek is:" <<seek_count<<endl;    
    return 0;
}