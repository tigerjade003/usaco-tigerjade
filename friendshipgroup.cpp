#include <bits/stdc++.h>
using namespace std;
#define int long long
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
struct dsu{
	vector<int> e;
	void init(int s){
		e.assign(s, -1);
	}
	int get(int u){
		return e[u]<0?u:e[u] = get(e[u]); 
	}
	int same(int u, int v){
		return get(u) == get(v);
	}
	int size(int u){
		return -e[get(u)];
	}
	bool merge(int u, int v){
		u = get(u), v = get(v);
		if(u==v) return false;
		if(e[u] > e[v]) swap(u, v);
		e[u] += e[v];
		e[v] = u;
		return true;
	}
};
int n, m;
vector<vector<int>> adj;
vector<int> degrees;
signed main(){
    cin >> n >> m;
    adj.assign(n, vector<int>());
    degrees.assign(n, 0);
    dsu dist;
    dist.init(n);
    set<pair<int, int>> nodes;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        degrees[a-1]++;
        degrees[b-1]++;
    }
    for(int i = 0; i<n; i++){
        nodes.insert({degrees[i], i});
    }
    int ans = 0;
    vector<int> nod;
    while(!nodes.empty()){
        auto [deg, node] = *nodes.begin();
        nodes.erase(nodes.begin());
        for(int nei: adj[node]){
            if(nodes.count({degrees[nei], nei})){
                nodes.erase({degrees[nei], nei});
                degrees[nei]--;
                nodes.insert({degrees[nei], nei});
            }
        }
        nod.push_back(node);
    }
    reverse(nod.begin(), nod.end());
    vector<bool> active(n, false);
    for(int i = 0; i<nod.size(); i++){
        int node = nod[i];
        active[node] = true;
        for(int nei: adj[node]){
            if(active[nei]){
                dist.merge(node, nei);
            }
        }
        int cur_deg = 0;
        for(int nei: adj[node]){
            if(active[nei]){
                cur_deg++;
            }
        }
        ans = max(ans, cur_deg * dist.size(node));
    }
    cout << ans << endl;
}