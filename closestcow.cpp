#include <bits/stdc++.h>
using namespace std;
#define int long long
int K, M, N;
vector<pair<int, int>> grasses;
vector<int> pfx;
signed main(){
    cin >> K >> M >> N;
    grasses.assign(K, {0, 0});
    pfx.assign(K, 0);
    for(int i = 0; i<K; i++){
        int a, b;
        cin >> a >> b;
        grasses[i] = {a, b};
    }
    sort(grasses.begin(), grasses.end());
    pfx[0] = grasses[0].second;
    for(int i = 1; i<K; i++){
        pfx[i] = pfx[i-1] + grasses[i].second;
    }
    
}