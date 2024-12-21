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
    int x, id, val;
};
bool comp(const thing &a, const thing &b){
    return a.x < b.x;
}
void solve(){
    vector<int> locations, cutoff, existing;
    vector<rule> rules;
    int N, Q;
    cin >> N >> Q;
    for(int i = 0; i<N; i++){
        int l;
        cin >> l;
        l *= 2;
        locations.push_back(l);
    }
    cutoff.assign(Q, 0);
    existing.assign(N, 0);
    for(int i = 0; i<Q; i++){
        int l, r;
        cin >> l >> r >> cutoff[i];
        l *= 2;
        r *= 2;
        l--;
        r++;
        rules.push_back({l, r, i});
    }
    sort(locations.begin(), locations.end());
    for(auto rule: rules){
        auto a = lower_bound(locations.begin(), locations.end(), rule.end);
        auto b = lower_bound(locations.begin(), locations.end(), rule.begin);
        cutoff[rule.id] -=  (a - b);
    }
    multiset<thing, decltype(&comp)> all(comp);
    for(int i = 0; i<N; i++){
        all.insert({locations[i], i, 0});
    }
    for(int i = 0; i<Q; i++){
        all.insert({rules[i].begin, i, 1});
        all.insert({rules[i].end, i, 2});
    }
    priority_queue<pair<int, int>> pq;
    int ans = 0;
    vector<bool> done(Q, false);
    for(auto entry: all){
        auto [x, id, val] = entry;
        if(val == 0){
            while(!pq.empty()){
                auto [val, idx] = pq.top();
                if(done[idx]) pq.pop();
                else{
                    break;
                }
            }
            if(pq.empty()){
                ans++;
                continue;
            }
            if(pq.top().first + ans < 0){
                ans++;
            }
        }
        else{
            if (val == 1){
                if(cutoff[id] + ans <= 0){
                    pq.push({cutoff[id]-ans, id});
                }
            }
            else if (val == 2){
                done[id] = true;
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