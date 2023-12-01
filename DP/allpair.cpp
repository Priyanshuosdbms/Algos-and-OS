#include<iostream>
using namespace std;


int allpair(int a[100][100] , int vertices)
{
    int i,j,n=vertices,k;
    int cost[100][100];

    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            cost[i][j] = a[i][j];

        }
    }
    
    for(k=0 ; k<n ; k++)
    {
        for(i=0 ; i<n ; i++)
        {
            for(j=0 ; j<n ;j++)
            {
                cost[i][j] = min(cost[i][j] , cost[i][k] + cost[k][j]);
            }
        }
    }

    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            a[i][j] = cost[i][j];
        }
    }
    return 0;
}


int main()
{
    int graph[100][100] , i , j , n;
    cout << "Enter number of vertcies in the graph :"<<endl;
    cin >>n;
    for(i=0 ; i<n ;i++)
    {
        for(j=0 ; j<n ; j++)
        {
          cin >> graph[i][j] ;
        }
    }

    for ( i = 0; i < n; i++)
    {
        for( j= 0; j < n; j++)
        {
            cout << graph[i][j] ;
        }
        cout << endl;
    }

    cout << "New converted all pair matrix is :"<<endl;
    allpair(graph,n);
     for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            cout<<graph[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}
