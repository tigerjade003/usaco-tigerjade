#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int T, N;
vector<int> maxmod4{2, 2, 1, 3};
vector<bool> composite(5e6+5, false);
int minturns[5000005] = {0, 1};
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    for(int i = 2; i < 5000005; i++) {
		if(!composite[i]) {
			for(int j = i; j < 5000005; j += i) {
				composite[j] = true;
			}
			maxmod4[i % 4] = i;
		}
		minturns[i] = (i - maxmod4[i % 4]) / 2 + 1;
	}
    cin >> T;
    while(T--){
        cin >> N;
        int ans = 5000005;
        for(int i = 0; i<N; i++){
            int k; cin >> k;
            if(minturns[k] / 2 < ans / 2) ans = minturns[k];
        }
        if(ans & 1) cout << "Farmer John" << endl;
        else cout << "Farmer Nhoj" << endl;
    }
    return 0;
}