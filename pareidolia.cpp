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
vector<char> bessie{'b', 'e', 's', 's', 'i', 'e'};
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> q;
    int ans = 0;
    for(int i = 0; i<q.size(); i++){
        int lookingfor = 0;
        int bcount = 0;
        for(int j = i; j<q.size(); j++){
            if(q[j] == bessie[lookingfor]){
                lookingfor++;
                if(lookingfor == 6){
                    lookingfor = 0;
                    bcount++;
                }
            }
            ans += bcount;
        }
    }
    cout << ans << endl;
}