#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
struct rule{
    int start, end, min;
};
int T, N, K;
vector<int> loc, nums;
vector<rule> rules;
vector<vector<int>> add, removes;
vector<set<int>> current;
vector<pair<int, int>> trees;
int main(){
    setIO();
    cin >> T;
    while(T--){
        cin >> N >> K;
        loc.assign(N, 0);
        rules.assign(K, {0, 0, 0});
        for(int i = 0; i<N; i++){
            cin >> loc[i];
        }
        sort(loc.begin(), loc.end());
        for(int i = 0; i<K; i++){
            int a, b, x;
            cin >> a >> b >> x;
            rules[i] = {a, b, x};
        }
        sort(rules.begin(), rules.end(), [](const rule&a, const rule&b){
            if(a.start != b.start){
                return a.start < b.start;
            }
            return a.end < b.end;
        });
        set<int> compressed(loc.begin(), loc.end());
        for(const auto &r: rules){
            compressed.insert(r.start);
            compressed.insert(r.end);
        }
        nums.assign(compressed.begin(), compressed.end());
        map<int, int> mapp;
        for(int i = 0; i<nums.size(); i++){
            mapp[nums[i]] = i;
        }
        for(int i = 0; i<N; i++){
            loc[i] = mapp[loc[i]];
        } 
        add.assign(compressed.size() + 1, vector<int>());
        removes.assign(compressed.size() + 1, vector<int>());
        vector<int> howmany(K, 0);
        for(int i = 0; i<K; i++){
            rules[i].start = mapp[rules[i].start];
            rules[i].end = mapp[rules[i].end];
            add[rules[i].start].push_back(i);
            removes[rules[i].end+1].push_back(i);
            howmany[i] = upper_bound(loc.begin(), loc.end(), rules[i].end) - lower_bound(loc.begin(), loc.end(), rules[i].start) - rules[i].min;
        }
        current.assign(compressed.size() + 1, set<int>());
        set<int> running;
        for(int i = 0; i<compressed.size()+1; i++){
            running.insert(add[i].begin(), add[i].end());
            for(int ruleIndex: removes[i]){
                running.erase(running.find(ruleIndex));
            }
            current[i] = running;
        }
        trees.assign(N, {0, 0});
        for(int i = 0; i<loc.size(); i++){
            trees[i] = {current[loc[i]].size(), loc[i]};
        }
        sort(trees.begin(), trees.end());
        int ans = 0;
        for(auto &[a, b]: trees){
            if(a == 0){
                ans++;
            }
            else{
                int minleeway = INT_MAX;
                for(int i: current[b]){
                    minleeway = min(minleeway, howmany[i]);
                }
                if(minleeway > 0){
                    for(int i: current[b]){
                        howmany[i] -= 1;
                    }
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
