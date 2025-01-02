#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, Q;
vector<int> unsorted, sorted, pfx;
signed main(){
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
    cin >> Q;
    int i, j;
    while(Q--){
        cin >> i >> j;
        if(j == unsorted[i]) cout << ans;
        else if(j > unsorted[i]){
            //find where j goes in the sorted array
            //find where unsorted[i] is in the sorted array
            int origpos = lower_bound(sorted.begin(), sorted.end(), unsorted[i]) - sorted.begin();
            int newpos = lower_bound(sorted.begin(), sorted.end(), j) - sorted.begin();
            
        }
        else{

        }
    }
}