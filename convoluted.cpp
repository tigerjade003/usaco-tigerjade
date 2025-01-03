#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define DEBUG true
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int N, M;
vector<pair<int, int>> intervals;
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    cin >> N >> M;
    intervals.assign(N, {0, 0});
    for(int i = 0; i<N; i++){
        int a, b;
        cin >> a >> b;
        intervals[i] = {a, b};
    }
    
}