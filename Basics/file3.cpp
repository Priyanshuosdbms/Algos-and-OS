#include <bits/stdc++.h>
using namespace std;
// 2 , 15 => 69,96
// 3 , 0 => -1 -1
// 4 , 24 => 1599
// 4 , 5 => 1112

int reverseDigits(int num) 
{ 
    int rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num * 10 + num % 10; 
        num = num / 10; 
    } 
    return rev_num; 
} 

int constval(int k, int curr_sum)
{
    if(k >= 10)
    k = 9;

    else
    {
        k = curr_sum;
    }

    return k;        
}

void minmax(int n, int k)
{
    int maxi = 0, mini = 0;
    if (n <= 0 || k == 0)
        cout << "-1 -1" << endl;

    else
    {
        for (int i = 0; i < n; i++)
        {
            if (k >= 10)
            {
                mini = (k - constval(k,mini)) * 10;
                cout << "Current mini: " << mini << endl;
                cout << "constval(): " << constval(k,mini) << endl;
                k = constval(k,mini);
                cout<< "current k: " << k << endl;
            }
        }

        mini = mini + (k);
        maxi = reverseDigits(mini);
        cout << mini << endl;
    }
}


int main()
{
    cout << "In file 3" << endl;
    int n, k;
    cin >> n >> k;
    minmax(n, k);
    return 0;
}