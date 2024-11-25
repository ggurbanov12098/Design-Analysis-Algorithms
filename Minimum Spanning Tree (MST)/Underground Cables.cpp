#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 1010
#define INF 1e9

int x[MAX], y[MAX];      // Coordinates of the points
double min_e[MAX];       // Minimum edge weight to include a point in MST
bool used[MAX];          // Tracks if a point is included in MST

// Function to calculate Euclidean distance between two points
inline double dist(int i, int j) {
    return sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
}

double Prim(int n) {
    fill(min_e, min_e + n, INF);
    memset(used, false, sizeof(used));
    min_e[0] = 0;  // Start from the first point
    double total_cost = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        // Find the point with the smallest edge weight not yet in the MST
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || min_e[j] < min_e[v])) {
                v = j;
            }
        }

        // Include the point into MST
        used[v] = true;
        total_cost += min_e[v];

        // Update minimum edge weights for all unvisited points
        for (int to = 0; to < n; to++) {
            if (!used[to]) {
                double d = dist(v, to);
                if (d < min_e[to]) {
                    min_e[to] = d;
                }
            }
        }
    }
    return total_cost;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        double result = Prim(n);
        printf("%.2lf\n", result);
    }
    return 0;
}
