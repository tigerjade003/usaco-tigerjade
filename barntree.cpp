#include <bits/stdc++.h>
using namespace std;
#define DEBUG true
#define int long long
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
struct request{
    int to, from, amount; //amount is negative if it wants to give it away
};
int N, totbales = 0, shouldbe;
vector<int> curs, inbound;
vector<vector<int>> adj;
vector<request> answer;
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    cin >> N;
    adj.assign(N, vector<int>());
    inbound.assign(N, 0);
    curs.assign(N, 0);
    for(int i = 0; i<N; i++){
        cin >> curs[i];
        totbales += curs[i];
    }
    shouldbe = totbales/N;
    for(int i = 0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        inbound[a]++;
        inbound[b]++;
    }
    queue<request> requests;
    stack<request> putoff;
    for(int i = 0; i<N; i++){
        if(adj[i].size() == 1){
            requests.push({adj[i][0], i, shouldbe-curs[i]});
        }
    }
    int q = requests.size();
    vector<bool> done(N, false);
    while(!requests.empty()){
        auto [from, to, val] = requests.front(); requests.pop();
        cout << from << " " << to << " " << val << endl;
        if(val < 0 || curs[to] >= val){
            curs[from] -= val;
            inbound[from]--;
            done[to] = true;
            answer.push_back({from, to, val});
            if(inbound[from] == 1){
                for(int k: adj[from]){
                    if(!done[k]){
                        requests.push({from, k, shouldbe-curs[from]});
                        break;
                    }
                }
            }
        }
        else{
            inbound[from]--;
            done[to] = true;
            if(inbound[from] == 1){
                for(int k: adj[from]){
                    if(!done[k]){
                        requests.push({from, k, shouldbe-curs[from]});
                        break;
                    }
                }
            }
            putoff.push({from, to, val});
        }
    }
    while(!putoff.empty()){
        auto [a, b, c] = putoff.top(); putoff.pop();
        answer.push_back({a, b, c});
    }
    cout << answer.size() << endl;
    for(int i = 0; i<answer.size(); i++){
        if(answer[i].amount > 0) cout << answer[i].to+1 << " " << answer[i].from+1 << " " << answer[i].amount << endl;
        else cout << answer[i].from+1 << " " << answer[i].to+1 << " " << -answer[i].amount << endl;
    }
}