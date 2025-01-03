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
vector<int> pfx, numbers;
vector<set<pair<int, int>>> pfx2;
vector<pair<int, int>> interval;
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    cin >> N >> M;
    pfx.assign(M+1, 0);
    pfx2.assign(2*M+2, set<pair<int, int>>());
    numbers.assign(2*M+2, 0);
    interval.assign(N, {0, 0});
    for(int i = 0; i<N; i++){
        int a, b;
        cin >> a >> b;
        pfx[a]++;
        pfx[b+1]--;
        interval[i] = {a, b};
    }
    for(int i = 1; i<M+1; i++){
        pfx[i] += pfx[i-1];
    }
    for(int i = 0; i<M+1; i++){
        cout << pfx[i] << endl;
    }
    cout << endl;
    for(int i = 0; i<=M; i++){
        for(int j = 0; j<=M; j++){
            if(pfx2[i+j].find({i, j}) == pfx2[i+j].end()){
                pfx2[i+j].insert({i, j});
                numbers[i+j] += pfx[i] * pfx[j];
            }
            //cout << (i + j) << " " << i << " " << j << " " << pfx2[i+j].size() << endl;
        }
    }
    for(int i = 0; i<=2*M; i++){
        cout << numbers[i] << endl;
    }
}