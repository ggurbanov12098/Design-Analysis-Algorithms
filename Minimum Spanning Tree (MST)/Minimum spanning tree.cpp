#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    // Vector to store edges as tuples: (weight, vertex1, vertex2)
    vector<tuple<int, int, int>> edges(m);
    for(auto &e : edges){
        cin >> get<1>(e) >> get<2>(e) >> get<0>(e); // (weight, u, v)
    }
    
    // Sort edges based on weight
    sort(edges.begin(), edges.end());
    
    // Initialize parent array for Union-Find
    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    // Lambda function to find the representative of a set
    auto find_set = [&](int x) -> int{
        while(x != parent[x]) x = parent[x];
        return x;
    };    
    int total_weight = 0;

    // Iterate through sorted edges and apply Kruskal's algorithm
    for(auto &e : edges){
        int w, u, v;
        tie(w, u, v) = e;
        int pu = find_set(u);
        int pv = find_set(v);
        if(pu != pv){
            parent[pu] = pv; // Union the sets
            total_weight += w; // Add edge weight to total
        }
    }
    cout << total_weight;
}