#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
#define int long long
int N, Tc, Tm;
vector<int> A, B, C;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
bool check(int w){
    int lx = max(1ll, Tc-w), hx = min(Tc + Tm - w - 1, Tc);
    for(int i = 0; i<N; i++){
        int d = Tc + Tm - w;
        if (B[i] - A[i] > 0){
            lx = max(lx, (-C[i] + B[i] * d + (B[i] - A[i] - 1)) / (B[i] - A[i]));
        }
        else if (A[i] - B[i] > 0){
            hx = min(hx, (C[i] - B[i] * d) / (A[i] - B[i]));
        }
        else{
            if (A[i] * d > C[i]){
                return false;
            }
        }
    }
    return (lx <= hx);
}
void solve(){
    cin >> N >> Tc >> Tm;//binary search for number of monies bessie should spend
    A.assign(N, 0);
    B.assign(N, 0);
    C.assign(N, 0);
    for(int i = 0; i<N; i++){
        cin >> A[i] >> B[i] >> C[i];
    }
    int lo = 0, hi = Tc + Tm - 2;
    while(hi > lo){
        int mid = (lo + hi)/2;
        if(check(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}