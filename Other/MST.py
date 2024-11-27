# Define the Edge structure
class Edge:
    def __init__(self, u, v, dist):
        self.u = u
        self.v = v
        self.dist = dist


# Disjoint Set (Union-Find) system
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n + 1))

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # Path compression
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            self.parent[root_v] = root_u  # Union by rank not needed here
            return True
        return False


# Kruskal's algorithm for Minimum Spanning Tree
def kruskal_mst(n, edges):
    # Initialize Disjoint Set
    ds = DisjointSet(n)

    # Sort edges by their weights
    edges.sort(key=lambda edge: edge.dist)

    # Process edges
    mst_weight = 0
    for edge in edges:
        if ds.union(edge.u, edge.v):
            mst_weight += edge.dist

    return mst_weight


# Input and output handling
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    # Number of vertices and edges
    n, m = map(int, data[0].split())

    # Read the edges
    edges = []
    for i in range(1, m + 1):
        u, v, dist = map(int, data[i].split())
        edges.append(Edge(u, v, dist))

    # Calculate MST weight using Kruskal's algorithm
    result = kruskal_mst(n, edges)
    print(result)
