#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<bool>> escapable;
int N, Q;
struct belt{
    int x, y;
};
int canescape = 0;
void dfs(int a, int b){
    canescape++;
    if(a < 0 || a >= N || b < 0 || b >= N || escapable[a][b]) return;
    escapable[a][b] = true;
    if(a > 0 && (grid[a-1][b] == '?' || grid[a-1][b] == 'R')){
        dfs(a-1, b);
    }
    if(a < N-1 && (grid[a+1][b] == '?' || grid[a+1][b] == 'L')){
        dfs(a+1, b);
    }
    if(b > 0 && (grid[a][b-1] == '?' || grid[a][b-1] == 'U')){
        dfs(a, b-1);
    }
    if(b < N-1 && (grid[a][b+1] == '?' || grid[a][b+1] == 'D')){
        dfs(a, b+1);
    }
}
int main(){
    cin >> N >> Q;
    grid.assign(N, vector<char>(N, '?'));
    vector<int> answers;
    escapable.assign(N, vector<bool>(N, false));
    vector<belt> belts(Q, {0, 0});
    for(int i = 0; i<Q; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        grid[a][b] = c;
        belts[i] = {a, b};
    }
    //now check all escapable cells;
    for(int i = 0; i < N; i++){
        //check grid[i][0], grid[i][N-1], grid[0][i], and grid[N-1][i]
        if(!escapable[i][0] && (grid[i][0] == '?' || grid[i][0] == 'L')){
            dfs(i, 0);
        }
        if(!escapable[i][N-1] && (grid[i][N-1] == '?' || grid[i][N-1] == 'R')){
            dfs(i, N-1);
        }
        if(!escapable[0][i] && (grid[0][i] == '?' || grid[0][i] == 'U')){
            dfs(0, i);
        }
        if((!escapable[N-1][i]) && (grid[N-1][i] == '?' || grid[N-1][i] == 'D')){
            dfs(N-1, i);
        }
    }
    answers.push_back(canescape);
    for(int i = Q-1; i>=0; i--){
        int x = belts[i].x;
        int y = belts[i].y;
        grid[x][y] = '?';
        if(x == 0 || y == 0 || x == N-1 || y == N-1 || escapable[x+1][y] || escapable[x-1][y] || escapable[x][y-1] || escapable[x][y+1]){
            dfs(x, y);
        }
        answers.push_back(canescape);
    }
    for(int i = 1; i<answers.size(); i++){
        cout << (N * N) - answers[i] << endl;
    }
}