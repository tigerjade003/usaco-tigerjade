#include <bits/stdc++.h>
using namespace std;
#define DEBUG true
#define ing lont long
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

struct request {
    int from, to, amount; 
};

int N, totbales = 0, shouldbe;
vector<int> curs;
vector<vector<int>> adj;
vector<request> answer;

void dfs(int node, int parent) {
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
            int transfer = curs[neighbor] - shouldbe;
            if (transfer != 0) {
                answer.push_back({neighbor, node, transfer});
                curs[node] += transfer;
                curs[neighbor] -= transfer;
            }
        }
    }
}

signed main() {
    if(DEBUG) setIO("test");
    else setIO();

    cin >> N;
    adj.assign(N, vector<int>());
    curs.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> curs[i];
        totbales += curs[i];
    }

    shouldbe = totbales / N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1); // Start DFS from node 0 with no parent

    cout << answer.size() << endl;
    for (auto &req : answer) {
        if(req.amount > 0) cout << req.from + 1 << " " << req.to + 1 << " " << req.amount << endl;
        else cout << req.to + 1 << " " << req.from+1 << " " << -req.amount << endl;
    }
    return 0;
}
