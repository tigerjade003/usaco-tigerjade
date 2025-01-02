#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG false
int N, Q;
vector<int> unsorted, sorted, pfx, pos;
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
    pfx.assign(N+1, 0);
    pos.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> unsorted[i];
    }
    iota(sorted.begin(), sorted.end(), 0);
    sort(sorted.begin(), sorted.end(), [&](int i, int j)
    {
        return unsorted[i] < unsorted[j];
    });
    for (int i = 0; i < N; i++)
    {
        pos[sorted[i]] = i;
    }
    int tot = 0;
    sort(unsorted.begin(), unsorted.end());
    for (int i = 0; i < N; i++)
    {
        pfx[i + 1] = pfx[i] + unsorted[i];
        tot += (i + 1) * unsorted[i];
    }
    cin >> Q;
    int i, j;
    while(Q--){
        int i, j;
        cin >> i >> j; i--;
        i = pos[i];
        int ans = tot;
        int newidx = lower_bound(unsorted.begin(), unsorted.end(), j) - unsorted.begin() - (bool) (j > unsorted[i]);
        ans -= (i + 1) * unsorted[i];
        if (newidx >= i) 
        {
            ans -= (pfx[newidx + 1] - pfx[i + 1]);
        }
        else 
        {
            ans += (pfx[i] - pfx[newidx]);
        }
        ans += (newidx + 1) * j;
        cout << ans << '\n';
    }
}