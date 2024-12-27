#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG false
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int N;
vector<vector<bool>> dir, visited; //false = R, true = D
vector<int> vertcost, horizcost;
vector<vector<int>> numof, numinto;
void dfs(int x, int y, int z){
    if(x < 0 || x >= N || y < 0 || y >= N) return;
    numof[x][y] += z;
    if(dir[x][y]){
        dfs(x+1, y, z);
    }
    else{
        dfs(x, y+1, z);
    }
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
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
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
    numinto.assign(N, vector<int>(N, 0));
    queue<pair<int, int>> lookat;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(numinto[i][j] == 0){
                lookat.push({i, j});
            }
            if(dir[i][j]){
                if(i < N-1){
                    numinto[i+1][j]++;
                }
            }
            else{
                if(j < N-1){
                    numinto[i][j+1]++;
                }
            }
        }
    }
    while(!lookat.empty()){
        auto [x, y] = lookat.front();
        lookat.pop();
        if(!dir[x][y]){
            if(y < N-1){
                numof[x][y+1] += numof[x][y];
                numinto[x][y+1]--;
                if(numinto[x][y+1] == 0){
                    lookat.push({x, y+1});
                }
            }
        }
        else{
            if(x < N-1){
                numof[x+1][y] += numof[x][y];
                numinto[x+1][y]--;
                if(numinto[x+1][y] == 0){
                    lookat.push({x+1, y});
                }
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