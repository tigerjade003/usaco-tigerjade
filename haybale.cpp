#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define int long long

void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int N;
vector<int> positions;
vector<pair<int, int>> wastes;
vector<bool> pos;
signed main(){
    cin >> N;
    positions.assign(N, 0);
    pos.assign(1e6, false);
    int right = 0;
    int left = 0;
    for(int i = 0; i<N; i++){
        int k;
        cin >> k;
        positions[i] = k-1;
        pos[k-1] - true;
        right += positions[i];
    }
    sort(positions.begin(), positions.end());
    int toleft = 0;
    int toright = N;
    for(int i = 0; i<=1e6; i++){
        wastes[i] = {left, right};
        if(pos[i]){
            toleft++;
            toright--;
        }
        left += toleft;
        right += toright;
    }
    
}