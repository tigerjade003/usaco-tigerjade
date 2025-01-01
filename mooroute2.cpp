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
struct flight{
    int starttime, to, endtime;
};
bool cmp(const flight& a, const flight& b){
    return a.starttime < b.endtime;
}
int N, M;
vector<vector<flight>> flights;
vector<int> layover;
signed main(){
    setIO();
    cin >> N >> M;
    flights.assign(M, vector<flight>());
    layover.assign(N, 0);
    for(int i = 0; i<M; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--;
        
    }
}