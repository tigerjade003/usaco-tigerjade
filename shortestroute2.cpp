#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long INF = LLONG_MAX;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    for (int src = 1; src <= n; ++src) {
        dist[src][src] = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int u = 1; u <= n; ++u) {
                if (dist[src][u] == INF) continue;
                for (auto [v, cost] : adj[u]) {
                    dist[src][v] = min(dist[src][v], dist[src][u] + cost);
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }

    return 0;
}