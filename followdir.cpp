#include <bits/stdc++.h>
using namespace std;
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
    for(int i = 0; i<N; i++){
        if(!dir[i][N-1]){

        }
        
    }
}
void update(int a, int b){

}
int main(){
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
        cin >> horizcost[i];
    }
    for(int i = 0; i<N; i++){
        cin >> vertcost[i];
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
    cout << 0 << endl;
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
    cout << determine();
    int Q;
    cin >> Q;
    for(int i = 0; i<Q; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        update(x, y);
        cout << determine();
    }
}