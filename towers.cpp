#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int N, M, K;
vector<pair<int, int>> cows;
priority_queue<pair<int, int>> towers;
signed main(){
    setIO();
    cin >> N >> M >> K;
    for(int i = 0; i<N; i++){
        int a, b;
        cin >> a >> b;
        cows.push_back({a, b});
    }
    sort(cows.rbegin(), cows.rend());
    towers.push({INT_MAX, M});
    int ans = 0;
    for(int i = 0; i<N; i++){
        while(towers.top().first >= cows[i].first+K && cows[i].second > 0){
            auto topt = towers.top();
            towers.pop();
            int size = min(topt.second, cows[i].second);
            cows[i].second -= size;
            ans += size;
            if (topt.second > size) {
                towers.push({topt.first, topt.second - size});
            }
            towers.push({cows[i].first, size});
        }
    }
    cout << ans << endl;
    return 0;
}