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
struct rule{
    int begin, end, min;
};
int N, Q;
vector<int> locations;
vector<rule> rules;
void solve(){
    cin >> N >> Q;
    locations.assign(N, 0);
    for(int i = 0; i<N; i++){
        int l;
        cin >> l;
        l *= 2;
        locations[i] = l;
    }
    sort(locations.begin(), locations.end());
    rules.assign(Q, {0, 0, 0});
    for(int i = 0; i<Q; i++){
        
    }

}
int main(){
    int T;
    while(T--){
        solve();
    }
}