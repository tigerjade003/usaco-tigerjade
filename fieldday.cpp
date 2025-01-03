#include <bits/stdc++.h>
using namespace std;
#define DEBUG true
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int C, N;
//vector<vector<bool>> teams; part of dumb thing
unordered_map<string, int> teams;
vector<vector<int>> lookat;
int main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> C >> N;
    //dumb method --> dumbest, only passes sample
    /*
    teams.assign(N, vector<bool>(C, false));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<C; j++){
            char q;
            cin >> q;
            teams[i][j] = (q == 'H');
        }
    }
    for(int i = 0; i<N; i++){
        int ans = 0;
        for(int j = 0; j<N; j++){
            int cur = 0;
            for(int q = 0; q<C; q++){
                if(teams[i][q] != teams[j][q]) cur++;
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }*/
    for(int i = 0; i<N; i++){
        string q;
        cin >> q;
        if(teams.count(q) > 0){
            lookat[teams.find(q) -> second].push_back(i);
        }
        else{
            teams.insert({q, lookat.size()});
            lookat.push_back(vector<int>{i});
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<lookat[i].size(); j++){
            cout << lookat[i][j] << endl;
        }
    }
    return 0;
}