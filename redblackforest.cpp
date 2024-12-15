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
        /*
        int min = 1, max = N, answer = 0;
        while(min <= max){
            int mid = (min + max)/2;
            if(works(mid, loc, rules)){
                answer = mid;
                max = mid - 1;
            }
            else{
                min = mid+1;
            }
        }
        cout << N-answer << endl;*/
        
    }
}
