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
vector<pair<short, short>> unuse;
vector<vector<bool>> donotch;
vector<vector<bool>> visited;
bool isuse = false;
void dfs(int x, int y){
    if(isuse) return;
    if(x < 0 || y < 0 || x >= N || y >= N) {
        isuse = true;
        return;
    }
    if(visited[x][y]) return;
    visited[x][y] = true;
    if(grid[x][y] != 0){
        int x1 = x;
        int y1 = y;
        if(grid[x][y] == 1){
            x1--;
        }
        else if(grid[x][y] == 2){
            x1++;
        }
        else if(grid[x][y] == 3){
            y1--;
        }
        else if(grid[x][y] == 4){
            y1++;
        }
        dfs(x1, y1);
    }
    else{
        dfs(x+1, y);
        dfs(x-1, y);
        dfs(x, y-1);
        dfs(x, y+1);
    }
}
void mark(int a, int b){
    if(a < 0 || b < 0 || a >= N || b >= N|| visited[a][b] || unusable[a][b]) return;
    unusable[a][b] = true;
    unuse.push_back({a, b});
    visited[a][b] = true;
    if(grid[a][b] != 0){
        int x1 = a;
        int y1 = b;
        if(grid[a][b] == 1){
            x1--;
        }
        else if(grid[a][b] == 2){
            x1++;
        }
        else if(grid[a][b] == 3){
            y1--;
        }
        else if(grid[a][b] == 4){
            y1++;
        }
        mark(x1, y1);
    }
    else{
        mark(a+1, b);
        mark(a-1, b);
        mark(a, b-1);
        mark(a, b+1);
    }
}
void checkall(){
    deque<pair<int, int>> needcheck;
    for(auto &q: unuse){
        needcheck.push_back({q.first+1, q.second});
        needcheck.push_back({q.first-1, q.second});
        needcheck.push_back({q.first, q.second+1});
        needcheck.push_back({q.first, q.second-1});
    }
    while(!needcheck.empty()){
        auto &e = needcheck.front();
        needcheck.pop_front();
        if(e.first <= 0 || e.second <= 0 || e.first >= N-1 || e.second >= N-1 || donotch[e.first][e.second]){
            continue;
        }
        if(unusable[e.first][e.second]){
            if(unusable[e.first+1][e.second] && unusable[e.first-1][e.second] && unusable[e.first][e.second+1] && unusable[e.first][e.second-1]){
                donotch[e.first][e.second] = true;
            }
            continue;
        }
        else{
            visited.assign(N, vector<bool>(N, false));
            isuse = false;
            dfs(e.first, e.second);
            if(!isuse){
                visited.assign(N, vector<bool>(N, false));
                mark(e.first,e.second);
            }
        }
    }
}
int main(){
    setIO();
    cin >> N >> Q;
    grid.assign(N, vector<short>(N, 0));
    unusable.assign(N, vector<bool>(N, false));
    donotch.assign(N, vector<bool>(N, false));
    for(int i = 0; i<Q; i++){
        short a, b;
        char c;
        cin >> a >> b;
        cin >> c;
        int dir;
        a--;
        b--;
        if(c == 'U'){
            dir = 1;
        }
        else if(c == 'D'){
            dir = 2;
        }
        else if(c == 'R'){
            dir = 4;
        }
        else{
            dir = 3;
        }
        grid[a][b] = dir;
        visited.assign(N, vector<bool>(N, false));
        isuse = false;
        //first dfs and find if it is usable or not.
        dfs(a, b);
        if(!isuse){
            visited.assign(N, vector<bool>(N, false));
            mark(a, b);
            checkall();
        }
        cout << unuse.size() << endl;
    }
}