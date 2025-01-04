#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define DEBUG false
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int T, n, m;
vector<vector<int>> adj, tovert;
vector<int> connecteds, srccost, dstcost;
void dfs(const int currv, const int id) {
  for(int child: adj[currv]) {
    if(connecteds[child] != id) {
      connecteds[child] = id;
      dfs(child, id);
    }
  }
}
signed main() {
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> T;
    while(T--){
        cin >> n >> m;
        adj.assign(n, vector<int>());
        for(int i = 0; i<m; i++){
            int a, b;
            cin >> a >> b; a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        connecteds.assign(n, 0);
        iota(connecteds.begin(), connecteds.end(), 0);
        for(int i = 0; i<n; i++){
            if(connecteds[i] == i){
                dfs(i, i);
            }
        }
        if(connecteds[0] == connecteds[n-1]){
            cout << 0 << endl;
            continue;
        }
        tovert.assign(n, vector<int>());
        for(int i = 0; i<n; i++){
            tovert[connecteds[i]].push_back(i);
        }
        int ans = 1e18;
        srccost.assign(n, 1e9);
        dstcost.assign(n, 1e9);
        int srcidx = 0;
        int dstidx = 0;
        for(int i = 0; i<n; i++){
            while(srcidx < tovert[connecteds[0]].size()){
                srccost[connecteds[i]] = min(srccost[connecteds[i]], (long long)abs(i - tovert[connecteds[0]][srcidx]));
                if(tovert[connecteds[0]][srcidx] < i) srcidx++;
                else break;
            }
            if(srcidx) srcidx--;
            while(dstidx < tovert[connecteds[n-1]].size()) {
                dstcost[connecteds[i]] = min(dstcost[connecteds[i]], (long long)abs(i - tovert[connecteds[n-1]][dstidx]));
                if(tovert[connecteds[n-1]][dstidx] < i) dstidx++;
                else break;
            }
            if(dstidx) dstidx--;
        }
        for(int i = 0; i<n; i++){
            ans = min(ans, srccost[i]*srccost[i] + dstcost[i]*dstcost[i]);
        }
        cout << ans << endl;
    }
    return 0;
}