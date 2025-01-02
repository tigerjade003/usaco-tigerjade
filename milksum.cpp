#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG true
int N, Q;
vector<int> unsorted, sorted, pfx;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> N;
    unsorted.assign(N, 0);
    sorted.assign(N, 0);
    pfx.assign(N, 0);
    for(int i = 0; i<N; i++){
        cin >> unsorted[i];
        sorted[i] = unsorted[i];
    }
    sort(sorted.begin(), sorted.end());
    pfx[0] = sorted[0];
    for(int i = 1; i<N; i++){
        pfx[i] = pfx[i-1] + sorted[i];
    }
    int ans = 0;
    for(int i = 0; i<N; i++){
        ans += (i+1)*sorted[i];
    }
    for(int i = 0; i<N; i++){
        cout << pfx[i] << " ";
    }
    cout << endl;
    cout << ans << endl << endl;
    cin >> Q;
    int i, j;
    while(Q--){
        cin >> i >> j;
        i--;
        if(j == unsorted[i]){
            cout << ans << endl;
            continue;
        }
        int origpos = lower_bound(sorted.begin(), sorted.end(), unsorted[i]) - sorted.begin();
        int newpos = lower_bound(sorted.begin(), sorted.end(), j) - sorted.begin();
        cout << origpos << " " << newpos << endl;
        int output = ans;
        output -= unsorted[i] * (origpos + 1);
        output += (newpos+1) * j;
        cout << output << endl;
        cout << pfx[newpos] << " " << pfx[origpos] << endl;
        cout << pfx[newpos+1] << " " << pfx[newpos-1] << endl;
        cout << pfx[origpos+1] << " " << pfx[origpos-1] << endl;
        if(j > unsorted[i]){
            output -= (pfx[newpos] - pfx[origpos]);
        }
        else{
            output += (pfx[origpos] - pfx[newpos]);
        }
        cout << output << endl << endl;
    }
}