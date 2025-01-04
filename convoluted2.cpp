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
vector<int> starting, ending;
vector<int> pfx;
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    cin >> N >> M;
    starting.assign(M+1, 0);
    ending.assign(M+1, 0);
    pfx.assign(2*M+2, 0);
    for(int i = 0; i<N; i++){
        int a, b;
        cin >> a >> b;
        starting[a]++;
        ending[b]++;
    }
    for(int i = 0; i<=M; i++){
        for(int j = 0; j<=M; j++){
            pfx[i+j] += starting[i]*starting[j];
            pfx[i+j+1] -= ending[i]*ending[j];
        }
    }
    long tot = 0;
    for(int i = 0; i<=2*M; i++){
        tot += pfx[i];
        cout << tot << endl;
    }
}