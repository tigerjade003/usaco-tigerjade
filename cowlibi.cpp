#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG true // binary search way
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
signed main(){
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
    vector<int> times(G, 0);
    for(int i = 0; i<G; i++){
        times[i] = incidents[i].first;
        //cout << times[i] << endl;
    }
    int innocent = 0;
    for(int i = 0; i<N; i++){
        int a, b, t;
        cin >> a >> b >> t;
        int indx1 = upper_bound(times.begin(), times.end(), t) - times.begin();
        if(indx1 == times.size()){//if it's later than the last one
            if(distance(a, incidents[indx1-1].second.first, b, incidents[indx1-1].second.second) > (t - times[indx1-1]) *  (t - times[indx1-1])){
                innocent++;
            }
        }
        else if(indx1 == 0){
            if(distance(a, incidents[indx1].second.first, b, incidents[indx1].second.second) > (t - times[indx1])* (t - times[indx1])){
                innocent++;
            }
        }
        else{
            int indx2 = indx1-1;
            if(distance(a, incidents[indx1].second.first, b, incidents[indx1].second.second) > (t - times[indx1]) *  (t - times[indx1]) || distance(a, incidents[indx2].second.first, b, incidents[indx2].second.second) > (t - times[indx2]) * (t - times[indx2])){
                innocent++;
            }
        }
    }
    cout << innocent << endl;
}