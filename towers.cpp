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
set<pair<int, int>> towers;
signed main(){
    cin >> N >> M >> K;
    for(int i = 0; i<N; i++){
        int a, b;
        cin >> a >> b;
        cows.push_back({a, b});
    }
    sort(cows.begin(), cows.end());
    towers.insert({-K, M});
    int ans = 0;
    for(int i = 0; i<N; i++){
        while(towers.begin() -> first < cows[i].first-K){
            int size = towers.begin() -> second;
            auto first = *towers.begin();
            towers.erase(towers.begin());
            if(first.second >= cows[i].second){
                size = cows[i].second;
                first.second-=cows[i].second;
            }
            else{
                size = first.second;
                first.second = 0;
            }
            if(first.second != 0){
                towers.insert(first.first, first.second);
            }
            towers.insert(cows[i].first, size);
            ans += size;
        }
    }
}