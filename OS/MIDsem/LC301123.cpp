#include<bits\stdc++.h>
using namespace std;

int bin(int x)
{
    int n = log(x)/log(2)+1;
    int ans=0;

    for(int i=0 ; i<n ; i++)
    {
        if(x % 2 == 1)
        {
            ans = ans * 10 + 1;
        }        

        else{
            
            ans= ans*10;
        }
        x = x / 2;
    }

    return ans;
}

int func(int a)
{
    int x = bin(a);
    // Change the rightmost bit 
    // Change the ith bit iff i-1 
    return x;    
}

int main()
{
    int n;
    cin >> n;
    cout << func(n);
    return 0;
}