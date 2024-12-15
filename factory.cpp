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
vector<vector<int>> visited;
vector<pair<short, short>> check;
int runnum = 0;
bool isuse = false;
void dfs(int x, int y) {
    stack<pair<int, int>> s;
    s.push({x, y});
    while (!s.empty() && !isuse) {
        auto [cx, cy] = s.top(); s.pop();
        if (cx < 0 || cy < 0 || cx >= N || cy >= N) {
            isuse = true;
            continue;
        }
        if (visited[cx][cy] == runnum) continue;
        visited[cx][cy] = runnum;
        if (grid[cx][cy] != 0) {
            int nx = cx, ny = cy;
            if (grid[cx][cy] == 1) nx--;
            else if (grid[cx][cy] == 2) nx++;
            else if (grid[cx][cy] == 3) ny--;
            else if (grid[cx][cy] == 4) ny++;
            s.push({nx, ny});
        } else {
            s.push({cx + 1, cy});
            s.push({cx - 1, cy});
            s.push({cx, cy + 1});
            s.push({cx, cy - 1});
        }
    }
}
void mark(int a, int b){
    if(a < 0 || b < 0 || a >= N || b >= N|| visited[a][b] == runnum || unusable[a][b]) return;
    unusable[a][b] = true;
    unuse.push_back({a, b});
    check.push_back({a, b});
    visited[a][b] = runnum;
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
    for(auto &q: check){
        if(q.first + 1 < N-1 && !donotch[q.first+1][q.second]){
            needcheck.push_back({q.first+1, q.second});
        }
        if(q.first-1 > 0 && !donotch[q.first-1][q.second]){
            needcheck.push_back({q.first-1, q.second});
        }
        if(q.second + 1 < N-1 && !donotch[q.first][q.second+1]){
            needcheck.push_back({q.first, q.second+1});
        }
        if(q.second-1 > 0 && !donotch[q.first][q.second-1]){
            needcheck.push_back({q.first, q.second-1});
        }
    }
    while(!needcheck.empty()){
        auto &e = needcheck.front();
        needcheck.pop_front();
        if(unusable[e.first][e.second]){
            if(unusable[e.first+1][e.second] && unusable[e.first-1][e.second] && unusable[e.first][e.second+1] && unusable[e.first][e.second-1]){
                donotch[e.first][e.second] = true;
            }
            continue;
        }
        else{
            runnum++;
            isuse = false;
            dfs(e.first, e.second);
            if(!isuse){
                runnum++;
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
    visited.assign(N, vector<int>(N, -1));
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
        isuse = false;
        runnum++;
        dfs(a, b);
        if(!isuse){
            runnum++;
            check.clear();
            mark(a, b);
            checkall();
        }
        cout << unuse.size() << endl;
    }
}