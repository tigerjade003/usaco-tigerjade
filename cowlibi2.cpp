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
int G, N;
double distance(int x1, int x2, int y1, int y2){
    return (x1-x2) * (x1-x2) + (y1-y2)*(y1-y2);
}
int main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> G >> N;
    vector<pair<int, pair<int, int>>> incidents(G);//time, then x and y
    for(int i = 0; i<G; i++){
        int a, b, c;
        cin >> a >> b >> c;
        incidents[i] = {c, {a, b}};
    }
    sort(incidents.begin(), incidents.end());
    int innocent = 0;
    vector<pair<int, pair<int, int>>> alibis(N);
    for(int i = 0; i<N; i++){
        int a, b, x;
        cin >> a >> b >> x;
        alibis[i] = {x, {a, b}};
    }
    sort(alibis.begin(), alibis.end());
    int a, b;
    for(a = 0, b = 0; a < G && b < N; b++){
        //a always points to the one after/equal to it.
        while(incidents[a].first < alibis[b].first){
            a++;
        }
        auto [x1, y1] = incidents[a].second;
        auto [x2, y2] = alibis[b].second;
        if(distance(x1, x2, y1, y2) > ((alibis[b].first - incidents[a].first) * (alibis[b].first - incidents[a].first))){
            innocent++;
        }
        else if(a > 0){
            int d = a-1;
            auto [x1, y1] = incidents[d].second;
            if(distance(x1, x2, y1, y2) > ((alibis[b].first - incidents[d].first) * (alibis[b].first - incidents[d].first))){
                innocent++;
            }
        }
    }
    for(int j = b; j<N; j++){
        auto [x1, y1] = incidents[G-1].second;
        auto [x2, y2] = alibis[j].second;
        if(distance(x1, x2, y1, y2) > ((alibis[b].first - incidents[G-1].first) * (alibis[b].first - incidents[G-1].first))){
            innocent++;
        }
    }
    cout << innocent << endl;
}