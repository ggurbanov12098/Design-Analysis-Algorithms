#include <stdio.h>
#include <string.h>

#define MAX 2001          // Maximum number of vertices
#define INF 0x3F3F3F3F    // Infinity value for no path
int g[MAX][MAX], used[MAX], dist[MAX]; // Graph matrix, used vertices, and distances

// Function to relax the edge (i, j)
void Relax(int i, int j) {
    if (dist[i] + g[i][j] < dist[j]) {
        dist[j] = dist[i] + g[i][j];
    }
}

int main() {
    int n, s, f; // Number of vertices, source, and destination
    scanf("%d %d %d", &n, &s, &f);

    memset(g, 0x3F, sizeof(g));     // Initialize graph with INF
    memset(used, 0, sizeof(used));  // Initialize all vertices as unused
    memset(dist, 0x3F, sizeof(dist)); // Initialize distances as INF

    dist[s] = 0; // Distance from source to itself is 0

    // Read the weight matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j] == -1) g[i][j] = INF; // Replace -1 with INF
        }
    }

    // Start Dijkstra's algorithm
    for (int i = 1; i < n; i++) {
        int min = INF, v = -1;

        // Find the unused vertex with the smallest distance
        for (int j = 1; j <= n; j++) {
            if (!used[j] && dist[j] < min) {
                min = dist[j];
                v = j;
            }
        }

        // If no vertex is found, the graph is disconnected
        if (v < 0) break;

        // Mark vertex v as used
        used[v] = 1;

        // Relax all outgoing edges from vertex v
        for (int j = 1; j <= n; j++) {
            if (!used[j] && g[v][j] != INF) {
                Relax(v, j);
            }
        }
    }

    // Print the result
    if (dist[f] == INF) {
        printf("-1\n"); // No path exists
    } else {
        printf("%d\n", dist[f]); // Print the shortest distance
    }

    return 0;
}
