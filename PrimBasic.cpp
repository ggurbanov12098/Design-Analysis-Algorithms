#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// Function to compute the squared distance between two points
int dist2(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

// Function to compute MST using Prim's algorithm (basic realization)
double primBasic(int n, vector<pair<int, int>> &coordinates) {
    const int INF = INT_MAX;

    vector<int> dist(n, INF);  // Distance to MST
    vector<bool> used(n, false);  // Track if vertex is in MST
    dist[0] = 0;  // Start from the first vertex
    double res = 0.0;

    for (int i = 0; i < n; i++) {
        int cur = -1;

        // Find the next vertex with the smallest distance
        for (int j = 0; j < n; j++) {
            if (!used[j] && (cur == -1 || dist[j] < dist[cur])) {
                cur = j;
            }
        }

        // Include this vertex in MST
        used[cur] = true;
        res += sqrt(dist[cur]);

        // Update distances to other vertices
        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                int d2 = dist2(coordinates[cur].first, coordinates[cur].second,
                               coordinates[j].first, coordinates[j].second);
                if (d2 < dist[j]) {
                    dist[j] = d2;
                }
            }
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> coordinates(n);
    for (int i = 0; i < n; i++) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }

    double result = primBasic(n, coordinates);
    cout.precision(6);
    cout << fixed << result << endl;

    return 0;
}
