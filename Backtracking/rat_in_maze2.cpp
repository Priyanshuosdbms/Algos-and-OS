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

    // Try all possible moves (Up, Down, Left, Right)
    char moves[] = {'U', 'D', 'L', 'R'};
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isSafe(newX, newY, maze, visited)) {
            visited[newX][newY] = true;
            path.push_back(moves[i]);
            findPaths(newX, newY, maze, visited, path);
            visited[newX][newY] = false; // Backtrack
            path.pop_back();
        }
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
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    findAllPaths(maze);
    return 0;
}
