#include <cstdio>
#include <cstring>
#include <vector>
#include <limits>
using namespace std;

const int MAX = 2001;
const int INF = numeric_limits<int>::max();

int n, m, s, f;
int g[MAX][MAX], used[MAX], dist[MAX], parent[MAX];

void PrintPath(int v) {
    vector<int> res;
    while (v != -1) {
        res.push_back(v);
        v = parent[v];
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

void Relax(int i, int j) {
    if (dist[i] + g[i][j] < dist[j]) {
        dist[j] = dist[i] + g[i][j];
        parent[j] = i;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &f);

    memset(g, 0x3F, sizeof(g));
    memset(used, 0, sizeof(used));

    for (int i = 0; i < m; i++) {
        int b, e, len;
        scanf("%d %d %d", &b, &e, &len);
        g[b][e] = g[e][b] = len;
    }

    fill(dist, dist + MAX, INF);
    dist[s] = 0;
    memset(parent, -1, sizeof(parent));

    for (int i = 1; i < n; i++) {
        int mn = INF, v = -1;
        for (int j = 1; j <= n; j++) {
            if (!used[j] && dist[j] < mn) {
                mn = dist[j];
                v = j;
            }
        }
        if (v == -1) break;

        for (int j = 1; j <= n; j++) {
            if (!used[j] && g[v][j] != INF) {
                Relax(v, j);
            }
        }
        used[v] = 1;
    }

    if (dist[f] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[f]);
        PrintPath(f);
    }

    return 0;
}
