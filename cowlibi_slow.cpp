#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG true //slow brute force way
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
bool comp(thing &a, thing &b){
    return a.t < b.t;
}
int G, N;
double distance(int x1, int x2, int y1, int y2){
    return (x1-x2) * (x1-x2) + (y1-y2)*(y1-y2);
}
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    cin >> G >> N;
    vector<int> timesof;
    vector<pair<int, int>> location;
    for(int i = 0; i<G; i++){
        int a, b, t;
        cin >> a >> b >> t;
        timesof.push_back(t);
        location.push_back({a, b});
    }
    int answer = 0;
    for(int i = 0; i<N; i++){
        int a, b, t;
        cin >> a >> b >> t;
        for(int j = 0; j<G; j++){
            if(distance(a, location[j].first, b, location[j].second) > ((t - timesof[j]) * (t - timesof[j]))){
                answer++;
                break;
            }
        }
    }
    cout << answer << endl;
}