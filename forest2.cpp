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
vector<int> loc;
vector<rule> rules;
int T, N, K;
int main(){
    setIO();
    cin >> T;
    while(T--){
        cin >> N >> K;
        loc.assign(N, 0);
        for(int i = 0; i<N; i++){
            cin >> loc[i];
        }
        sort(loc.begin(), loc.end());
        rules.assign(K, {0, 0, 0});
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
        vector<int> nums;
        for(int i = 0; i<K; i++){
            compressed.insert(rules[i].start);
            compressed.insert(rules[i].end);
        }
        map<int, int> mapp;
        int index = 0;
        for(int k: compressed){
            mapp[k] = index++;
            nums.push_back(k);
        }
        for(int i = 0; i<N; i++){
            loc[i] = mapp[loc[i]];
        }
        for(int i = 0; i<K; i++){
            rules[i].start = mapp[rules[i].start];
            rules[i].end = mapp[rules[i].end];
        }
        vector<vector<int>> add(2*compressed.size() + 2);
        vector<vector<int>> remove(2*compressed.size() + 2);
        for(int i = 0; i<K; i++){
            add[2*rules[i].start].push_back(i);
            remove[2*rules[i].end+1].push_back(i);
        }
        vector<int> needmax(2*compressed.size()+2, 0);
        set<int> maxs;
        for(int i = 0; i<2*compressed.size()+2; i++){
            if(i % 2 == 0) maxs.insert(add[i].begin(), add[i].end());
            else{
                for(int j  = 0; j<remove[i].size(); j++){
                    maxs.erase(remove[i][j]);
                }
            }
            int size = 0;
            for(int k: maxs){
                size = max(size, rules[k].min);
            }
            needmax[i] = size;
        }
        int max = 0;
        int ans = 0;
        max = needmax[0];
        for(int i = 1; i<needmax.size(); i++){
            if(needmax[i] < needmax[i-1]){
                ans += max;
            }
            else{
                max = needmax[i];
            }
        }
        cout << ans << endl;
    }
}