#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph

// Function to check if it's safe to color the vertex v with color c
bool isSafe(int graph[V][V], int v, int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Recursive function to solve graph coloring problem
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, v, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0; // Backtrack
        }
    }

    return false;
}

// Wrapper function to solve graph coloring problem
bool graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist.\n");
        return false;
    }

    printf("Solution exists: The following are the assigned colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
    return true;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 0}
    };
    int m = 3; // Number of colors

    if (!graphColoring(graph, m)) {
        printf("Solution does not exist.\n");
    }

    return 0;
}

bool Safe(int graph[V][V] , int v , int color[] , int c)
{
    for(int i=0 ; i<V ; i++)
    {
        if(graph[v][i] && color[i] == c)
        return false;
    }
    return true;
}

bool graphcolor(int graph[V][V] , int m , int color[] , int v)
{
    if(v == V)
    {
        return true;
    }

    for(int c=1 ; c<=m ; c++) // m indicates maximum amount of color
    {
        if(Safe(graph,v,color,c))
        {
            color[v] = c;

            if(graphcolor(graph , m , color , v+1))
            return true;

            color[v] = 0;
        }

    }

    return false;
}

bool graphcoloring(int graph[V][V] , int m)
{
    int color[V];
    for(int i=0 ; i<V ; i++)
    color[i] = 0;

    if(!graphcolor(graph,m,color,0))
    {
        printf("No solution\n");
        return false;
    }

    printf("Solution- : \n");
    for(int i=0 ; i<V ; i++)
    {
        printf("");
    }
    
    return true;
}