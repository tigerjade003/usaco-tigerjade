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
int ans;
struct belt{
    short x, y, dir;
};
vector<belt> belts;
vector<vector<bool>> visited;
bool found = false;
bool dfs(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N || grid[x][y] == 0) return false;
    if(visited[x][y] || unusable[x][y]) return true;
    visited[x][y] = true;
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
    else{
        y1++;
    }
    return dfs(x1, y1);
}
void mark(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N || unusable[x][y]) return;
    unusable[x][y] = true;
    unuse.push_back({x, y});
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
    else{
        y1++;
    }
    mark(x1, y1);
}
void look(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N || unusable[x][y] || found || visited[x][y]) return;
    visited[x][y] = true;
    if(x == 0 || y == 0 || x == N-1 || y == N-1){ 
        found = true; 
        return;
    }
    else{
        look(x+1, y);
        look(x-1, y);
        look(x, y+1);
        look(x, y-1);
    }
}
void mark2(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N || unusable[x][y]) return;
    unusable[x][y] = true;
    mark2(x-1,y);
    mark2(x+1, y);
    mark2(x, y-1);
    mark2(x, y+1);
}
void check(){
    queue<pair<int, int>> checks;
    for(auto &q: unuse){
        if(!donotch[q.first][q.second]){
            checks.push({q.first-1, q.second});
            checks.push({q.first+1, q.second});
            checks.push({q.first, q.second-1});
            checks.push({q.first, q.second+1});
        }
    }
    while(checks.size() > 0){
        visited.assign(N, vector<bool>(N, false));
        pair<int, int> a = checks.front();
        checks.pop();
        if(a.first <= 0 || a.first >= N-1 || a.second <= 0 || a.second >= N-1){
            continue;
        }
        if(unusable[a.first][a.second]){
            if(unusable[a.first+1][a.second] && unusable[a.first-1][a.second] && unusable[a.first][a.second+1] && unusable[a.first][a.second-1]){
                donotch[a.first][a.second] = true;
            }
            continue;
        }
        else{
            found = false;
            look(a.first, a.second);
            if(!found){
                mark2(a.first, a.second);
            }
        }
    }
}
int main(){
    setIO();
    cin >> N >> Q;
    grid.assign(N, vector<short>(N, 0));
    belts.assign(Q, {0, 0, 0});
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
        //first dfs and find if it is usable or not.
        bool use = dfs(a, b);
        //if not, mark unusable and increase counter.
        if(use){
            mark(a, b);
            //now check if anything is surrounded by the unusable
            check();
        }
        cout << unuse.size() << endl;
    }
}