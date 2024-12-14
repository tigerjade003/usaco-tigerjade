#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int N;
signed main(){
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        vector<int> cakes(N);
        vector<int> prefix(N);
        int total = 0;
        for(int i = 0; i<N; i++){
            cin >> cakes[i];
            total += cakes[i];
            if(i > 0){
                prefix[i] = prefix[i-1] + cakes[i];
            }
            else{
                prefix[i] = cakes[i];
            }
        }
        int maxCake = 0;
        for(int i = -1; i<(N-2)/2; i++){
            int cur = 0;
            if(i >= 0){
                cur += prefix[i];
            }
            cur += prefix[N-1] - prefix[N-(N-2)/2 + i];
            maxCake = max(maxCake, cur);
        }
        cout << total - maxCake << " " << maxCake << endl;
    }
}