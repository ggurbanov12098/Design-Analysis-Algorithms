#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

#define MAX 5001
#define INF 1e9

int x[MAX], y[MAX];      // Coordinates of cities
int used[MAX];           // Tracks if a city is included in MST
double min_e[MAX];       // Minimum edge weight to include a city in MST

// Function to calculate squared distance between two cities
inline double dist(int i, int j) {
    return sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
}

double Prim(int n) {
    memset(used, 0, sizeof(used));
    fill(min_e, min_e + n, INF);

    min_e[0] = 0;  // Start from the first city
    double total_cost = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;

        // Find the city with the smallest edge weight not yet in the MST
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || min_e[j] < min_e[v])) {
                v = j;
            }
        }

        // Include the city into MST
        used[v] = 1;
        total_cost += min_e[v];

        // Update minimum edge weights for all unvisited cities
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
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double result = Prim(n);

    // Print the result with at least 10^-3 accuracy
    printf("%.9lf\n", result);

    return 0;
}
