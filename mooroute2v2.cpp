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
    short start; int starttime; short to; int endtime;
};
bool cmp(const flight& a, const flight& b){
    if(a.start != b.start) return a.start < b.start;
    if(a.starttime != b.starttime) return a.starttime < b.starttime;
    if(a.to != b.to) return a.to < b.to;
    return a.endtime < b.endtime;
}
int N, M;
vector<flight> flights;
vector<int> layover, earliest, fromports;
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> N >> M;
    flights.assign(M, {0, 0, 0, 0});
    layover.assign(N, 0);
    short a, c;
    int b, d;
    for(int i = 0; i<M; i++){
        cin >> a >> b >> c >> d;
        a--, c--;
        flights[i] = {a, b, c, d};
    }
    sort(flights.begin(), flights.end(), cmp);
    fromports.assign(M, 0);
    for(int i = 0; i<M_LN10; i++){
        cin >> layover[i];
        fromports[i] = flights[i].start;
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
        int begin = lower_bound(fromports.begin(), fromports.end(), airport) - fromports.begin();
        int end = upper_bound(fromports.begin(), fromports.end(), airport) - fromports.begin();
        for(int i = begin; i< end; i++){
            if(time <= flights[i].starttime && (earliest[flights[i].to] > flights[i].endtime || earliest[flights[i].to] == -1)){
                check.push({flights[i].to, flights[i].endtime});
            }
        }
    }
    for(auto q: earliest){
        cout << q << endl;
    }
}