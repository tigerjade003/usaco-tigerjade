#include <bits/stdc++.h>
using namespace std;

int main(){
    
}
int q, l;
vector<vector<int>> adj;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
void dfs(int a, int b){
    tin[a] = ++timer;
    up[a][0] = b;
    for(int i = 0; i<= l; ++i){
        up[a][i] = up[up[a][i-1]][i-1];
    }
    for(int u: adj[a]){
        if(u != b){
            dfs(u, a);
        }
    }
}