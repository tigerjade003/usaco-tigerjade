#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG false //two pointers way
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
struct thing{
    int x, y, t;
};
bool cmp(const thing &a, const thing &b){
    return a.t < b.t;
}
int G, N;
bool reachable(thing a, thing b){
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y)* (a.y - b.y) <= (a.t - b.t) * (a.t - b.t));
}
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> G >> N;
    vector<thing> incidents(G);
    for(int i = 0; i<G; i++){
        int a, b, c;
        cin >> a >> b >> c;
        incidents[i] = {a, b, c};
    }
    sort(incidents.begin(), incidents.end(), cmp);
    int innocent = 0;
    vector<thing> alibis(N);
    for(int i = 0; i<N; i++){
        int a, b, x;
        cin >> a >> b >> x;
        alibis[i] = {a, b, x};
    }
    sort(alibis.begin(), alibis.end(), cmp);
    int a, b;
    for(a = 0, b = 0; b < N; b++){
        while(a < G - 1 && incidents[a].t < alibis[b].t){
            a++;
        }
        if(!reachable(incidents[a], alibis[b])){
            innocent++;
        }
        else if(a > 0){
            int d = a-1;
            if(!reachable(incidents[d], alibis[b])){
                innocent++;
            }
        }
    }
    cout << innocent << endl;
}