#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int dijkstra(int n, int s, int f, const vector<vector<int>>& graph) {
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    distances[s] = 0;

    for (int i = 0; i < n; i++) {
        int min_distance = INF, u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != -1 && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }

    return distances[f] == INF ? -1 : distances[f];
}

int main() {
    int n, s, f;
    cin >> n >> s >> f;
    s--, f--; // Convert to zero-based indexing

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int result = dijkstra(n, s, f, graph);
    cout << result << endl;

    return 0;
}
