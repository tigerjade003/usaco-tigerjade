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
int N;
vector<vector<bool>> dir; //false = R, true = D
vector<int> vertcost, horizcost;
vector<vector<int>> numof;
vector<vector<bool>> visited;
void dfs(int x, int y, int z){
    if(x < 0 || x >= N || y < 0 || y >= N || visited[x][y]) return;
    visited[x][y] = true;
    numof[x][y] += z;
    if(dir[x][y]){
        dfs(x+1, y, z);
    }
    else{
        dfs(x, y+1, z);
    }
}
bool hasno(int x, int y){
    bool works = true;
    if(x > 0 && dir[x-1][y]){
        works = false;
    }
    if(y > 0 && !dir[x][y-1]){
        works = false;
    }
    return works;
}
int determine(){
    int cost = 0;
    for(int i = 0; i<N; i++){
        if(!dir[i][N-1]){
            cost += numof[i][N-1] * vertcost[i];
        }
        if(dir[N-1][i]){
            cost += numof[N-1][i] * horizcost[i];
        }
    }
    return cost;
}
void update(int x, int y){
    if(dir[x][y]){
        dfs(x+1, y, -numof[x][y]);
        dfs(x, y+1, numof[x][y]);
    }
    else{
        dfs(x, y+1, -numof[x][y]);
        dfs(x+1, y, numof[x][y]);
    }
    dir[x][y] = !dir[x][y];
}
signed main(){
    cin >> N;
    dir.assign(N, vector<bool>(N, false));
    horizcost.assign(N, 0);
    vertcost.assign(N, 0);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            char q;
            cin >> q;
            dir[i][j] = (q == 'D'); 
        }
        cin >> vertcost[i];
    }
    for(int i = 0; i<N; i++){
        cin >> horizcost[i];
    }
    numof.assign(N, vector<int>(N, 1));
    visited.assign(N, vector<bool>(N, false));
    queue<pair<int, int>> lookat;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(hasno(i, j)){
                lookat.push({i, j});
            }
        }
    }
    while(!lookat.empty()){
        auto [x, y] = lookat.front();
        lookat.pop();
        if(visited[x][y]){
            continue;
        }
        visited[x][y] = true;
        if(dir[x][y]){
            if(x < N-1){
                numof[x+1][y] += numof[x][y];
                lookat.push({x+1, y});
            }
        }
        else{
            if(y < N-1){
                numof[x][y+1] += numof[x][y];
                lookat.push({x, y+1});
            }
        }
    }
    cout << determine() << endl;
    int Q;
    cin >> Q;
    for(int i = 0; i<Q; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        update(x, y);
        cout << determine() << endl;
    }
}