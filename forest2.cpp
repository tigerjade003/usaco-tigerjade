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
int T, N, K; vector<int> loc;
int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        vector<int> loc(N);
        for(int i = 0; i<N; i++){
            cin >> loc[i];
        }
        sort(loc.begin(), loc.end());
        vector<rule> rules;
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
        for(int i = 0; i<K; i++){
            compressed.insert(rules[i].start);
            compressed.insert(rules[i].end);
        }
        map<int, int> mapp;
        int index = 0;
        for(int k: compressed){
            mapp[k] = index++;
        }
        for(int i = 0; i<N; i++){
            loc[i] = mapp[loc[i]];
        }
        for(int i = 0; i<K; i++){
            rules[i].start = mapp[rules[i].start];
            rules[i].end = mapp[rules[i].end];
        }
        
    }
}