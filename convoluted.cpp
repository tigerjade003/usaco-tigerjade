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
vector<int> pfx;
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    cin >> N >> M;
    intervals.assign(N, {0, 0});
    pfx.assign(M*2+2, 0);
    for(int i = 0; i<N; i++){
        int a, b;
        cin >> a >> b;
        intervals[i] = {a, b};
    }
    sort(intervals.begin(), intervals.end());
    //dumb method = method #1
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            pfx[intervals[i].first + intervals[j].first]++;
            pfx[intervals[i].second + intervals[j].second + 1]--;
        }
    }
    cout << pfx[0] << endl;
    for(int i = 1; i<2*M + 1; i++){
        pfx[i] += pfx[i-1];
        cout << pfx[i] << endl;
    }
}