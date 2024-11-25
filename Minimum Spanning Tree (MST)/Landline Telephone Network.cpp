#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 1000000

struct Edge {
    int u, v, dist;
    Edge(int u, int v, int dist) : u(u), v(v), dist(dist) {}
};

vector<Edge> edges;
vector<int> danger;
vector<int> parent;

// Comparator for sorting edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.dist < b.dist;
}

// Find operation for Union-Find
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Union operation for Union-Find
bool unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
        return true;
    }
    return false;
}

int main() {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    // Initialize the disjoint-set system
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // Read unsafe houses and initialize their danger levels
    danger.resize(n + 1, 0);
    for (int i = 0; i < p; i++) {
        int u;
        scanf("%d", &u);
        danger[u] = INF;
    }

    // Read edges and compute danger levels
    for (int i = 0; i < m; i++) {
        int u, v, dist;
        scanf("%d %d %d", &u, &v, &dist);

        // Update danger levels for unsafe houses
        if (danger[u] > 0 && danger[v] == 0) {
            danger[u] = min(danger[u], dist);
        } else if (danger[v] > 0 && danger[u] == 0) {
            danger[v] = min(danger[v], dist);
        }

        // Add edges connecting only safe houses
        if (danger[u] == 0 && danger[v] == 0) {
            edges.emplace_back(u, v, dist);
        }
    }

    // If there are no edges in the graph
    if (m == 0) {
        puts("0");
        return 0;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Kruskal's algorithm to find MST
    int res = 0, cnt = 0;
    for (const auto& edge : edges) {
        if (unionSets(edge.u, edge.v)) {
            res += edge.dist;
            cnt++;
        }
    }

    // Connect unsafe houses to the MST
    for (int i = 1; i <= n; i++) {
        if (danger[i] > 0) {
            res += danger[i];
            cnt++;
        }
    }

    // Check if the graph is connected and the MST is valid
    if (cnt != n - 1 || res > INF) {
        puts("impossible");
    } else {
        printf("%d\n", res);
    }
    return 0;
}
