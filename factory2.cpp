#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int N, Q;
struct belt{
    int a, b, c;
};
vector<vector<short>> grid;
vector<belt> belts;
vector<vector<int>> visited;
int numrun = 0;
void dfs(int a, int b){
    if(a < 0 || b < 0 || a >= N || b >= N) {
        
    }
}
int main(){
    cin >> N >> Q;
    grid.assign(N, vector<short>(false));
    while(Q--){
        short a, b, c;
        a--;
        b--;
        char dir;
        cin >> a >> b;
        cin >> dir;
        if(dir == 'U'){
            c = 1;
        }
        else if(dir == 'D'){
            c = 2;
        }
        else if(dir == 'L'){
            c = 3;
        }
        else{
            c = 4;
        }
        belts.push_back({a, b, c});
        grid[a][b] = c;
    }
    visited.assign(N, vector<int>(N, -1));
    //dfs from every unvisited node and see if it is unusable or not.
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(!visited[i][j]){
                dfs(i, j);
            }
        }
    }
}