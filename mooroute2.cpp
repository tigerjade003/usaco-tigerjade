#include <bits/stdc++.h>
using namespace std;
#define DEBUG true
#define endl '\n'
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
struct flight{
    int starttime, to, endtime;
};
bool cmp(const flight& a, const flight& b){
    return a.starttime < b.endtime;
}
int N, M;
vector<vector<flight>> flights;
vector<int> layover, earliest;
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> N >> M;
    flights.assign(M, vector<flight>());
    layover.assign(N, 0);
    for(int i = 0; i<M; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, c--;
        flights[a].push_back({b, c, d});
    }
    for(int i = 0; i<N; i++){
        for(auto adj: flights[i]){
            cout << adj.starttime << " " << adj.endtime << " " << adj.to << endl;
        }
    }
    for(int i = 0; i<N; i++){
        cin >> layover[i];
    }
    earliest.assign(N, -1);
    earliest[0] = 0;
    queue<pair<int, int>> check;
    check.push({0, -layover[0]});
    bool checks = false;
    while(!check.empty()){
        auto [airport, time] = check.front(); check.pop();
        if(earliest[airport] != time) {
            continue;
        }
        time += layover[airport];
        for(auto [toport, start, end]: flights[airport]){
            if(start >= time && (earliest[toport] == -1 || earliest[toport] > end)){
                check.push({toport, end});
                earliest[toport] = end;
            }
        }
    }
    for(auto q: earliest){
        cout << q << endl;
    }
}