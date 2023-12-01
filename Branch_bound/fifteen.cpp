#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional> // Include this for the 'function' template
#include <algorithm>

using namespace std;

// 8 puzzle problem
/*
// Define the dimensions of the puzzle
const int N = 3; // 3x3 puzzle

// Define the directions to move: Up, Down, Left, Right
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const string dir[] = {"Up", "Down", "Left", "Right"};

// Struct to represent a state of the puzzle
struct State {
    vector<vector<int>> board;
    int x, y; // Empty cell coordinates
    int g, h; // g: cost to reach this state, h: heuristic value
    string move; // The move made to reach this state
};

// Function to calculate the Manhattan distance heuristic
int calculateHeuristic(const vector<vector<int>>& board) {
    int heuristic = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] != 0) {
                int targetX = (board[i][j] - 1) / N;
                int targetY = (board[i][j] - 1) % N;
                heuristic += abs(i - targetX) + abs(j - targetY);
            }
        }
    }
    return heuristic;
}

// Function to check if a state is valid and within bounds
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Function to swap two elements in the board
void swapCells(vector<vector<int>>& board, int x1, int y1, int x2, int y2) {
    swap(board[x1][y1], board[x2][y2]);
}

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if two boards are equal
bool areBoardsEqual(const vector<vector<int>>& board1, const vector<vector<int>>& board2) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board1[i][j] != board2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Function to implement the A* algorithm
int solvePuzzle(vector<vector<int>>& start, vector<vector<int>>& goal) {
    priority_queue<State, vector<State>, function<bool(State, State)>> pq(
        [](const State& a, const State& b) {
            return a.g + a.h > b.g + b.h;
        });

    map<vector<vector<int>>, int> cost;

    State initial;
    initial.board = start;
    initial.x = initial.y = 0;
    initial.g = 0;
    initial.h = calculateHeuristic(initial.board);
    initial.move = "";
    pq.push(initial);

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (areBoardsEqual(current.board, goal)) {
            printBoard(current.board);
            return current.g;
        }

        cost[current.board] = current.g;

        for (int d = 0; d < 4; ++d) {
            int newX = current.x + dx[d];
            int newY = current.y + dy[d];

            if (isValid(newX, newY)) {
                State nextState = current;
                swapCells(nextState.board, current.x, current.y, newX, newY);
                nextState.x = newX;
                nextState.y = newY;
                nextState.g += 1;
                nextState.h = calculateHeuristic(nextState.board);
                nextState.move = current.move + dir[d];

                if (cost.find(nextState.board) == cost.end() || nextState.g < cost[nextState.board]) {
                    pq.push(nextState);
                }
            }
        }
    }

    return -1; // No solution found
}

int main() {
    vector<vector<int>> start = {{1, 2, 3}, {4, 0, 5}, {6, 7, 8}};
    vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    cout << "Initial board:" << endl;
    printBoard(start);

    int moves = solvePuzzle(start, goal);

    if (moves != -1) {
        cout << "Reached goal state in " << moves << " moves." << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

const int N = 4; // 4x4 puzzle

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const string dir[] = {"Up", "Down", "Left", "Right"};

struct State {
    vector<vector<int>> board;
    int x, y;
    int g, h;
    string move;
};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void swapCells(vector<vector<int>>& board, int x1, int y1, int x2, int y2) {
    swap(board[x1][y1], board[x2][y2]);
}

void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool areBoardsEqual(const vector<vector<int>>& board1, const vector<vector<int>>& board2) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board1[i][j] != board2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int calculateHeuristic(const vector<vector<int>>& board) {
    int heuristic = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] != 0) {
                int targetX = (board[i][j] - 1) / N;
                int targetY = (board[i][j] - 1) % N;
                heuristic += abs(i - targetX) + abs(j - targetY);
            }
        }
    }
    return heuristic;
}

int solvePuzzle(vector<vector<int>>& start, vector<vector<int>>& goal) {
    priority_queue<State, vector<State>, function<bool(State, State)>> pq(
        [](const State& a, const State& b) {
            return a.g + a.h > b.g + b.h;
        });

    map<vector<vector<int>>, int> cost;

    State initial;
    initial.board = start;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (initial.board[i][j] == 0) {
                initial.x = i;
                initial.y = j;
                break;
            }
        }
    }
    initial.g = 0;
    initial.h = calculateHeuristic(initial.board);
    initial.move = "";
    pq.push(initial);

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (areBoardsEqual(current.board, goal)) {
            printBoard(current.board);
            return current.g;
        }

        cost[current.board] = current.g;

        for (int d = 0; d < 4; ++d) {
            int newX = current.x + dx[d];
            int newY = current.y + dy[d];

            if (isValid(newX, newY)) {
                State nextState = current;
                swapCells(nextState.board, current.x, current.y, newX, newY);
                nextState.x = newX;
                nextState.y = newY;
                nextState.g += 1;
                nextState.h = calculateHeuristic(nextState.board);
                nextState.move = current.move + dir[d];

                if (cost.find(nextState.board) == cost.end() || nextState.g < cost[nextState.board]) {
                    pq.push(nextState);
                }
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> start = {
        {1, 3, 2, 8},
        {5, 6, 7, 12},
        {9, 10, 11, 4},
        {13, 14, 15, 0}
    };

    vector<vector<int>> goal = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };

    cout << "Initial board:" << endl;
    printBoard(start);

    int moves = solvePuzzle(start, goal);

    if (moves != -1) {
        cout << "Reached goal state in " << moves << " moves." << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
