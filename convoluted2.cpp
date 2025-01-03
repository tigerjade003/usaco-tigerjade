#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define DEBUG false
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int N, M;
vector<pair<int, int>> intervals;
vector<int> pfx, firsts, seconds;
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    cin >> N >> M;
    intervals.assign(N, {0, 0});
    firsts.assign(N, 0);
    seconds.assign(N, 0);
    pfx.assign(M*2+2, 0);
    for(int i = 0; i<N; i++){
        int a, b;
        cin >> a >> b;
        intervals[i] = {a, b};
    }
    sort(intervals.begin(), intervals.end());
    for(int i = 0; i<N; i++){
        firsts[i] = intervals[i].first;
        seconds[i] = intervals[i].second;
    }
    for(int i = 0; i<2 * M; i++){
        int ans = 0;
        for(int i = 0; i<N; i++){
            if(intervals[i].first > i){
                break;
            }
            
        }
    }
}