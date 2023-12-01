#include<iostream>
using namespace std;

class prims
{

};

class kruskal
{

};


int main()
{
    int i,j,n;
    cout << "Enter the size of the matrix" <<endl;
    cin >>  n;
    int matrix[n][n];
    for(i = 0 ; i< n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            cin >> matrix[i][j];
        }
    }

    return 0; 
}