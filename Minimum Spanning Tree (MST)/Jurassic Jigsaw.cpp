#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <climits>
using namespace std;

// Function to compute Hamming distance between two strings
int hammingDistance(const string& s1, const string& s2) {
    int dist = 0;
    for (size_t i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            dist++;
        }
    }
    return dist;
}

// Prim's Algorithm to construct the Minimum Spanning Tree
pair<int, vector<pair<int, int>>> evolutionaryTree(int n, const vector<string>& sequences) {
    vector<bool> used(n, false);
    vector<int> minEdge(n, INT_MAX);
    vector<int> parent(n, -1);
    minEdge[0] = 0;

    int totalWeight = 0;
    vector<pair<int, int>> edges;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || minEdge[j] < minEdge[v])) {
                v = j;
            }
        }

        used[v] = true;
        totalWeight += minEdge[v];
        if (parent[v] != -1) {
            edges.push_back({parent[v], v});
        }

        for (int to = 0; to < n; to++) {
            if (!used[to]) {
                int dist = hammingDistance(sequences[v], sequences[to]);
                if (dist < minEdge[to]) {
                    minEdge[to] = dist;
                    parent[to] = v;
                }
            }
        }
    }

    return {totalWeight, edges};
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> sequences(n);

    for (int i = 0; i < n; i++) {
        cin >> sequences[i];
    }

    auto [totalWeight, edges] = evolutionaryTree(n, sequences);

    cout << totalWeight << endl;
    for (const auto& [u, v] : edges) {
        cout << u << " " << v << endl;
    }
    return 0;
}
