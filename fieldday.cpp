#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
#define endl '\n';
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int C, N;
int main() {
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
	cin >> C >> N;
	vector<int> bin;
	vector<int> dist(1 << C, C);
	vector<int> stor_pct(1 << ((C + 1) / 2));
	for (int i = 0; i < stor_pct.size(); ++i)
		stor_pct[i] = __builtin_popcount(i);
	for (int kk = 0; kk < N; kk++) {
		string s;
		cin >> s;
		int mask = 0;
		for (int i = 0; i < C; ++i) mask ^= (s[i] - 'G') << i;
		for (int i = 0; i < (1 << (C / 2)); ++i){
            dist[mask^i] = min(dist[mask^i], stor_pct[i]);
        }
		bin.push_back(mask);
	}
	for (int x : bin) {
		x = (1 << C) - 1 - x;
		int ret = C;
		for (int i = 0; i < (1 << (C - C / 2)); ++i){
            ret = min(ret, dist[x ^ (i << (C / 2))] + stor_pct[i]);
        }
		cout << C - ret << endl;
	}
}