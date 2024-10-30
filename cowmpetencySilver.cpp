#include <bits/stdc++.h>
using namespace std;
#define int long long
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int N, Q, C;
        cin >> N >> Q >> C;
        vector<int> sofar(N, 0);
        vector<int> tree(4*N, 0);
    }
}