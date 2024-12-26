#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
struct rule{
    int begin, end, id;
};
struct thing{
    int start, end, id, val;
};
bool comp(const thing &a, const thing &b){
    if(a.start == b.start) return a.val < b.val;
    return a.start < b.start;
}
void solve(){
    int N, Q;
    cin >> N >> Q;
    vector<int> locations(N);
    for(int i = 0; i<N; i++){
        cin >> locations[i];
    }
    sort(locations.begin(), locations.end());
    multiset<thing, decltype(&comp)> all(comp);
    for(int i = 0; i<Q; i++){
        int l, r, t;
        cin >> l >> r >> t;
        int existing = upper_bound(locations.begin(), locations.end(), r) - lower_bound(locations.begin(), locations.end(), l);
        all.insert({l, -1, r, existing - t});
    }
    sort(locations.begin(), locations.end());
    for(int i = 0; i<N; i++){
        all.insert({locations[i], 0, 0, 0});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int ans = 0;
    for (auto [l, type, r, cut] : all) {
        if (type == -1) {
            pq.push({ans + cut, r});
        } else {
            while (!pq.empty() && pq.top().second < l) {
                pq.pop();
            }
            if (pq.empty() || pq.top().first != ans) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
int main(){
    if(DEBUG)
        setIO("test");
    else{
        setIO();
    }
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}