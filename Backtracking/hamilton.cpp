#include <stdio.h>

#define V 5 // Number of vertices

void printSolution(int path[]);

// Check if the current vertex can be added to the Hamiltonian cycle
int isSafe(int v, int pos, int path[], int graph[V][V]) {
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

// Find Hamiltonian cycle using backtracking
int hamiltonianCycleUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        // Check if there is an edge from the last vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos, path, graph)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1) == 1)
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

// Find and print Hamiltonian cycle
int hamiltonianCycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from the first vertex (0)
    path[0] = 0;

    if (hamiltonianCycleUtil(graph, path, 1) == 0) {
        printf("No Hamiltonian cycle exists\n");
        return 0;
    }

    printSolution(path);
    return 1;
}

void printSolution(int path[]) {
    printf("Hamiltonian cycle exists:\n");
    for (int i = 0; i < V; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[0]);
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}
