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
vector<vector<short>> grid;//0 is unused, 1 is up, 2 is down, 3 is left, 4 is right
vector<vector<bool>> unusable; //true if unusable, false if usable
vector<pair<short, short>> unusable;
int ans;
struct belt{
    short x, y, dir;
};
vector<belt> belts;
vector<vector<bool>> visited;
bool dfs(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N || grid[x][y] == 0) return false;
    if(visited[x][y]) return true;
    visited[x][y] = true;
    int x1 = x;
    int y1 = y;
    if(grid[x][y] == 1){
        y1--;
    }
    else if(grid[x][y] == 2){
        y1++;
    }
    else if(grid[x][y] == 3){
        x1--;
    }
    else{
        x1++;
    }
    return dfs(x1, y1);
}
int main(){
    setIO();
    cin >> N >> Q;
    grid.assign(N, vector<short>(N, 0));
    belts.assign(Q, {0, 0, 0});
    for(int i = 0; i<N; i++){
        short a, b;
        char c;
        
    }
}