#include <bits/stdc++.h>
using namespace std;
#define DEBUG true
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int T, N;
vector<int> nums;
vector<bool> sieve;
void solve(){
    cin >> N;
    nums.assign(N, 0);
    for(int i = 0; i<N; i++){
        cin >> nums[i];
        
    }
}
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    //generate the sieve up to 5x10^6
    sieve.assign(5e6+10, true);
    sieve[0] = false;
    for(int i = 2; i<5e6+10; i++){
        if(sieve[i]){
            for(int j = i*2; j<5e6+10; j+=i) sieve[j] = false;
        }
    }
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}