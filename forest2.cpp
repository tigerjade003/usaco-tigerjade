#include <bits/stdc++.h>
using namespace std;
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
int main(){
    setIO();
    cin >> T;
    while(T--){
        cin >> N >> K;
        vector<int> loc(N);
        vector<rule> rules(K);
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
        vector<int> nums(compressed.begin(), compressed.end());
        map<int, int> mapp;
        for(int i = 0; i<nums.size(); i++){
            mapp[nums[i]] = i;
        }
        for(int i = 0; i<N; i++){
            loc[i] = mapp[loc[i]];
        }
        for(int i = 0; i<K; i++){
            rules[i].start = mapp[rules[i].start];
            rules[i].end = mapp[rules[i].end];
        }
        vector<vector<int>> add(nums.size());
        vector<vector<int>> remove(nums.size());
        for(int i = 0; i<K; i++){
            add[rules[i].start].push_back(i);
            remove[rules[i].end].push_back(i);
        }
        vector<int> needmax(2*nums.size(), 0);
        multiset<int> maxs;
        for(int i = 0; i<nums.size(); i++){
            for(int ruleIndex: add[i]){
                maxs.emplace(rules[ruleIndex].min);
            }
            if(!maxs.empty()){
                needmax[2*i] = *maxs.rbegin();
            }
            for(int ruleIndex: remove[i]){
                maxs.erase(maxs.find(rules[ruleIndex].min));
            }
            if(!maxs.empty()){
                needmax[2*i+1] = *maxs.rbegin();
            }
        }
        int max = needmax[0];
        int ans = 0;
        bool adds= true;
        for(int i = 1; i<needmax.size(); i++){
            if(needmax[i] <= needmax[i-1]){
                if(adds && needmax[i] < needmax[i-1]){
                    ans += max;
                    max = 0;
                    adds = false;
                }
            }
            else{
                max = needmax[i];
                adds = true;
            }
        }
        cout << N-ans << endl;
    }
}