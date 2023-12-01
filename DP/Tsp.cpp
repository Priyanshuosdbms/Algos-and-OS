#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9; // Infinity value

// Function to calculate the distance between two cities
double distance(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

// Dynamic programming function to solve TSP
double solveTSP(int mask, int pos, vector<vector<double>>& dp, const vector<pair<int, int>>& cities) {
    if (mask == (1 << cities.size()) - 1) {
        return distance(cities[pos], cities[0]); // Return to starting city
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    double ans = INF;
    for (int next = 0; next < cities.size(); ++next) {
        if (!(mask & (1 << next))) { // Check if city 'next' is not visited yet
            ans = min(ans, distance(cities[pos], cities[next]) + solveTSP(mask | (1 << next), next, dp, cities));
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int n; // Number of cities
    cin >> n;

    vector<pair<int, int>> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }

    vector<vector<double>> dp(1 << n, vector<double>(n, -1.0));

    double minDistance = solveTSP(1, 0, dp, cities); // Start from city 0

    cout << "Minimum TSP distance: " << minDistance << endl;

    return 0;
}
