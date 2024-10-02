#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";
int n, m;
int P = 9973;
int M = 1e9+9;
void setIO(string file = ""){
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size()))
  {
    auto z = freopen((file + ".in").c_str(), "r", stdin);
    z = freopen((file + ".out").c_str(), "w", stdout);
  }
}
vector<vector<int>> prefixhash;
void hasher(string q, int z){
    int ans = 0;
    for(int i = 0; i<q.length(); i++){
        ans *= P;
        ans += q[i];
        ans %= M;
        prefixhash[z][i] = ans;
    }
}
signed main(){
    cin >> n >> m;
    prefixhash.assign(n, vector<int>());
    for(int i = 0; i<n; i++){
        string q;
        cin >> q;
        prefixhash[i].assign(q.length(), 0);
        hasher(q, i);
    }
    set<int> dupes;
    for(int i = 0; i<n; i++){
        dupes.insert(prefixhash[i][prefixhash[i].size()-1]);
    }
    cout << dupes.size();
    return 0;
}
