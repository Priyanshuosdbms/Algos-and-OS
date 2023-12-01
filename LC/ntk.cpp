#include <iostream>
#include <limits.h>

using namespace std;

int allpair(int a[100][100], int vertices)
{
    int i, j, n = vertices, k;
    int cost[100][100];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cost[i][j] = a[i][j];
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][k] != -1 && cost[k][j] != -1)
                {
                    if (cost[i][j] == -1 || cost[i][k] + cost[k][j] < cost[i][j])
                    {
                        cost[i][j] = cost[i][k] + cost[k][j];
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = cost[i][j];
        }
    }
    return 0;
}

int main()
{
    int times[100][3], n, i, j, adj_matrix[100][100];
    int src, dest, l;
    int temp1, temp2, temp3;
    cout << "Enter the number of connections" << endl;
    cin >> n;
    cout << "Enter times array" << endl;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> times[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << times[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter number of nodes\n";
    cin >> l;

    cout << "Enter source node\n";
    cin >> src;
    cout << "Enter destination vertex" << endl;
    cin >> dest;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < l; j++)
        {
            adj_matrix[i][j] = -1;
        }
    }

    temp1 = temp2 = temp3 = 0;

    for (i = 0; i < n; i++)
    {
        temp1 = times[i][0] - 1;
        temp2 = times[i][1] - 1;
        temp3 = times[i][2];
        adj_matrix[temp1][temp2] = temp3;
    }

    cout << "adj matrix is" << endl;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < l; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    allpair(adj_matrix, l);
    cout << "Ntk matrix is :" << endl;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < l; j++)
        {
            cout << adj_matrix[i][j] << "  ";
        }
        cout << endl;
    }

    cout<<"Output : "<<adj_matrix[src-1][dest-1]<<endl;
    return 0;
}