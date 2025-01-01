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
    int starttime; short to; int endtime;
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
    flights.assign(N, vector<flight>());
    layover.assign(N, 0);
    short a, c;
    int b, d;
    for(int i = 0; i<M; i++){
        cin >> a >> b >> c >> d;
        a--, c--;
        flights[a].push_back({b, c, d});
    }
    for(int i = 0; i<N; i++){
        cin >> layover[i];
    }
    earliest.assign(N, -1);
    queue<pair<int, int>> check;
    check.push({0, 0});
    bool checks = false;
    while(!check.empty()){
        auto [airport, time] = check.front(); check.pop();
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
        for(auto j: flights[airport]){
            auto [start, toport, end] = j;
            if(start >= time && (earliest[toport] == -1 || earliest[toport] > end)){
                check.push({toport, end});
            }
        }
    }
    for(auto q: earliest){
        cout << q << endl;
    }
}