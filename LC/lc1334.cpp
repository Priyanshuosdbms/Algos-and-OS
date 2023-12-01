#include <iostream>
using namespace std;

int cityret(int array[100][100], int nodes)
{
}
int cityret(int adj_matrix[100][100], int n, int distanceThreshold)
{
    int minCities = n + 1; // Initialize with a value larger than the maximum number of cities
    int ansCity = -1;

    for (int city = 0; city < n; ++city)
    {
        int reachableCities = 0;

        for (int destCity = 0; destCity < n; ++destCity)
        {
            if (city != destCity && adj_matrix[city][destCity] <= distanceThreshold)
            {
                ++reachableCities;
            }
        }

        if (reachableCities <= minCities)
        {
            minCities = reachableCities;
            ansCity = city;
        }
    }

    return ansCity;
}








int main()
{
    int i, j, k, l, adj_matrix[100][100];
    int n, dist_thresh;
    int temp1, temp2, temp3;
    /*
    cout << "Enter number of connections"<<endl;
    cin >> n;
    cout << "Enter the edges respectively"<<endl;
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            cin >> edges[i][j];
        }
    }
    */

    int edges[][3] = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}}; /*[[0,1,3],[1,2,1],[1,3,4],[2,3,1]],*/
    n = 4;

    cout << "Enter number of cities" << endl;
    cin >> l;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < l; j++)
        {
            adj_matrix[i][j] = -1;
        }
    }

    cout << "Adjacency Matrix is" << endl;
    for (i = 0; i < n; i++)
    {
        temp1 = edges[i][0];
        temp2 = edges[i][1];
        temp3 = edges[i][2];
        adj_matrix[temp1][temp2] = temp3;
        adj_matrix[temp2][temp1] = temp3;
    }

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < l; j++)
        {
            cout << adj_matrix[i][j] << "   ";
        }
        cout << endl;
    }

    cout << "Enter distance threshold" << endl;
    cin >> dist_thresh;

    cout << "Output :" << cityret(adj_matrix, l, dist_thresh) << endl;
    ;
    return 0;
}
