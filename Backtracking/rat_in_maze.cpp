#include <iostream>
#include <vector>

using namespace std;

#define N 4 // Change N to the size of your matrix

void printPath(vector<char>& path) {
    for (char move : path) {
        cout << move << " ";
    }
    cout << endl;
}

bool isSafe(int x, int y, int maze[N][N], vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && !visited[x][y]);
}

void findPaths(int x, int y, int maze[N][N], vector<vector<bool>>& visited, vector<char>& path) {
    if (x == N - 1 && y == N - 1) {
        printPath(path);
        return;
    }

    if (x - 1 >= 0 && isSafe(x - 1, y, maze, visited)) { // Up
        visited[x - 1][y] = true;
        path.push_back('U');
        findPaths(x - 1, y, maze, visited, path);
        visited[x - 1][y] = false; // Backtrack
        path.pop_back();
    }

    if (x + 1 < N && isSafe(x + 1, y, maze, visited)) { // Down
        visited[x + 1][y] = true;
        path.push_back('D');
        findPaths(x + 1, y, maze, visited, path);
        visited[x + 1][y] = false; // Backtrack
        path.pop_back();
    }

    if (y - 1 >= 0 && isSafe(x, y - 1, maze, visited)) { // Left
        visited[x][y - 1] = true;
        path.push_back('L');
        findPaths(x, y - 1, maze, visited, path);
        visited[x][y - 1] = false; // Backtrack
        path.pop_back();
    }

    if (y + 1 < N && isSafe(x, y + 1, maze, visited)) { // Right
        visited[x][y + 1] = true;
        path.push_back('R');
        findPaths(x, y + 1, maze, visited, path);
        visited[x][y + 1] = false; // Backtrack
        path.pop_back();
    }
}

void findAllPaths(int maze[N][N]) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<char> path;

    if (maze[0][0] == 1) {
        visited[0][0] = true;
        findPaths(0, 0, maze, visited, path);
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {1, 1, 1, 1}
    };

    findAllPaths(maze);
    return 0;
}
