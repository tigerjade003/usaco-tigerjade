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
int N;
vector<int> curs;
int main(){
    cin >> N;
    curs.assign(N, 0);
    for(int i = 0; i<N; i++) cin >> curs[i];
    
}