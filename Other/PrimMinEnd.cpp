#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

// Function to compute the squared distance between two points
int dist2(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

// Function to compute MST using Prim's algorithm with min_e and end_e
double primMinE(int n, vector<pair<int, int>> &coordinates) {
    const int INF = INT_MAX;

    vector<int> min_e(n, INF);  // Minimum distance to MST
    vector<int> end_e(n, -1);  // Tracks the vertex adding this edge to MST
    vector<bool> used(n, false);  // Tracks if vertex is in MST
    min_e[0] = 0;  // Start from the first vertex
    double res = 0.0;

    for (int i = 0; i < n; i++) {
        int cur = -1;

        // Find the next vertex with the smallest min_e value
        for (int j = 0; j < n; j++) {
            if (!used[j] && (cur == -1 || min_e[j] < min_e[cur])) {
                cur = j;
            }
        }

        // Include this vertex in MST
        used[cur] = true;
        if (end_e[cur] != -1) {
            res += sqrt(min_e[cur]);
        }

        // Update min_e and end_e for the other vertices
        for (int to = 0; to < n; to++) {
            if (!used[to]) {
                int d2 = dist2(coordinates[cur].first, coordinates[cur].second,
                               coordinates[to].first, coordinates[to].second);
                if (d2 < min_e[to]) {
                    min_e[to] = d2;
                    end_e[to] = cur;
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

    double result = primMinE(n, coordinates);
    cout.precision(6);
    cout << fixed << result << endl;

    return 0;
}
