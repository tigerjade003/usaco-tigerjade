#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
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
bool comp(const flight& a, const flight& b){
    if(a.starttime != b.starttime) return a.starttime < b.starttime;
    return a.to < b.to;
}
int N, M;
vector<vector<flight>> flights;
vector<int> layover, earliest;
vector<int> idx;
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> N >> M;
    flights.assign(N, vector<flight>());
    layover.assign(N, 0);
    idx.assign(N, 0);
    int a, b, c, d;
    for(int i = 0; i<M; i++){
        cin >> a >> b >> c >> d;
        a--, c--;
        flights[a].push_back({b, c, d});
    }
    for(int i = 0; i<N; i++){
        cin >> layover[i];
        idx[i] = flights[i].size()-1;
        sort(flights[i].begin(), flights[i].end(), comp);
    }
    earliest.assign(N, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> check;
    check.push({0, 0});
    bool checks = false;
    pair<int, int> q;
    while(!check.empty()){
        auto [time, airport] = check.top(); check.pop();        
        if(earliest[airport] != -1 && earliest[airport] < time) {
            continue;
        }
        earliest[airport] = time;
        if(checks){
            time += layover[airport];
        }
        else{
            checks = true;
        }
        while(idx[airport] >= 0 && flights[airport][idx[airport]].starttime >= time){
            check.push({flights[airport][idx[airport]].endtime, flights[airport][idx[airport]].to});
            idx[airport]--;
        }
    }
    for(auto q: earliest){
        cout << q << endl;
    }
}