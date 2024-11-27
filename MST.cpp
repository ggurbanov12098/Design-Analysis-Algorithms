#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define the structure for graph edges
struct Edge {
    int u, v, dist;
};

// Comparator function to sort edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.dist < b.dist;
}

// Disjoint Set System
vector<int> parent;

// Function to find the representative of the set containing n
int Repr(int n) {
    while (n != parent[n]) {
        parent[n] = parent[parent[n]]; // Path compression
        n = parent[n];
    }
    return n;
}

// Function to unite sets containing x and y
bool Union(int x, int y) {
    x = Repr(x);
    y = Repr(y);
    if (x == y) return false; // Already in the same set
    parent[y] = x; // Union
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize the parent array for disjoint set
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    // Read the edges of the graph
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].dist;
    }

    // Sort the edges in increasing order of their weights
    sort(edges.begin(), edges.end(), compareEdges);

    // Apply Kruskal's algorithm
    int res = 0;
    for (int i = 0; i < m; i++) {
        if (Union(edges[i].u, edges[i].v)) {
            res += edges[i].dist;
        }
    }
    
    // Print the weight of the minimum spanning tree
    cout << res << endl;
    return 0;
}
