#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, dist;
    Edge(int u, int v, int dist) : u(u), v(v), dist(dist) {}
};

// Global variables
vector<Edge> edges;
vector<int> parent;
set<pair<int, int>> mstEdges;

// Find the representative of the set containing `x` (Union-Find with path compression)
int findSet(int x) {
    if (x != parent[x]) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

// Union operation for Union-Find (joins two sets)
bool unionSets(int x, int y) {
    int rootX = findSet(x);
    int rootY = findSet(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
        return true;
    }
    return false;
}

// Comparator for sorting edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.dist < b.dist;
}

int main() {
    int tests;
    scanf("%d", &tests);

    while (tests--) {
        // Read the input
        int n, m, p, q;
        scanf("%d %d %d %d", &n, &m, &p, &q);

        // Initialize Union-Find structure
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Read the edges
        edges.clear();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edges.emplace_back(u, v, w);
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end(), compareEdges);

        // Clear MST edge set for the current test case
        mstEdges.clear();

        // Kruskal's algorithm to construct MST
        for (const auto& edge : edges) {
            if (unionSets(edge.u, edge.v)) {
                mstEdges.insert({min(edge.u, edge.v), max(edge.u, edge.v)});
            }
        }

        // Check if the edge (p, q) is part of the MST
        if (mstEdges.find({min(p, q), max(p, q)}) != mstEdges.end()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}
