#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
#define int long long
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
string q;
vector<int> pfxsum;
vector<char> bessie{'b', 'e', 's', 's', 'i', 'e'};
signed main(){
    cin >> q;
    int lookat = 0;
    int bcount = 0;
    pfxsum.assign(q.size(), 0);
    for(int i = 0; i<q.size(); i++){
        if(q[i] == bessie[lookat]){
            lookat++;
            if(lookat == 6){
                bcount++;
                lookat = 0;
            }
        }
        pfxsum[i] = bcount;
    }
    for(int i = 1; i<q.size(); i++){
        pfxsum[i] += pfxsum[i-1];
    }
    

}