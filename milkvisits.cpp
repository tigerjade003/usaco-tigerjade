#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int N, L;
vector<vector<int>> graph;
vector<bool> isG;
vector<int> whatgroup;
int curgroup;
void dfs(int a){
    whatgroup[a] = curgroup;
    for(auto q: graph[a]){
        if(isG[a] == isG[q] && whatgroup[q] == -1){
            dfs(q);
        }
    }
}
int main(){
    setIO("milkvisits");
    cin >> N >> L;
    isG.assign(N, false);
    for (int i = 0; i< N; i++){
        char q;
        cin >> q;
        isG[i] = (q == 'G');
    }
    graph.assign(N, vector<int>());
    whatgroup.assign(N, -1);
    for(int i = 0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    curgroup = -1;
    for(int i = 0; i<N; i++){
        if(whatgroup[i] == -1){
            curgroup++;
            dfs(i);
        }
    }
    string ans = "";
    for(int i = 0; i<L; i++){
        int a, b; char c;
        cin >> a >> b >> c;
        a--;
        b--;
        if(whatgroup[a] != whatgroup[b]){
            ans += '1';
        }
        else{
            if(c == 'G'){
                if(isG[a]) ans += '1';
                else ans += '0';
            }
            else{
                if(isG[a]) ans += '0';
                else ans += '1';
            }
        }
    }
    cout << ans << endl;
    return 0;
}