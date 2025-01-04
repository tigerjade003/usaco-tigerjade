#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define DEBUG false
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int T, N, M, x, y, has1, hasN;
vector<vector<int>> adj, connecteds;
vector<bool> visited;
int curlevel;
void dfs(int k){
    if(k == 0) has1 = curlevel;
    if(k == N-1) hasN = curlevel;
    visited[k] = true;
    connecteds[curlevel].push_back(k);
    for(auto q: adj[k]){
        if(!visited[q]){
            dfs(q);
        }
    }
}
int finddist(int first, int second){
    int p1 = 0, p2 = 0, mindiff = LLONG_MAX;
    while(p1 < connecteds[first].size() && p2 < connecteds[second].size()){
        mindiff = min(mindiff, abs((connecteds[first][p1] - connecteds[second][p2]) * (connecteds[first][p1] - connecteds[second][p2])));
        if (connecteds[first][p1] < connecteds[second][p2]) {
            p1++;
        } else {
            p2++;
        }
    }
    return mindiff;
}
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> T;
    while(T--){
        cin >> N >> M;
        adj.assign(N, vector<int>());
        for(int i = 0; i< M; i++){
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        curlevel = -1;
        visited.assign(N, false);
        for(int i = 0; i<N; i++){
            if(!visited[i]){
                curlevel++;
                connecteds.push_back(vector<int>());
                dfs(i);
                cout << "";
            }
        }
        if(has1 == hasN){
            cout << 0 << endl;
            connecteds = vector<vector<int>>();
            continue;
        }
        for(int i = 0; i<connecteds.size(); i++){
            sort(connecteds[i].begin(), connecteds[i].end());
        }
        int mindistance = LLONG_MAX;
        mindistance = min(mindistance, finddist(has1, hasN));
        //cout << mindistance << endl;
        //cout << connecteds.size() << endl;
        for(int i = 0; i<connecteds.size(); i++){
            if(i != has1 && i != hasN){
                //cout << i << " " << has1 << " " << hasN << endl;
                mindistance = min(mindistance, finddist(has1, i) + finddist(i, hasN));
                //cout << mindistance << endl;
            }
        }
        cout << mindistance << endl;
        connecteds = vector<vector<int>>();
    }
    return 0;
}