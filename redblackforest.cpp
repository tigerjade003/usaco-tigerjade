#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int N;
struct law{
    int start, end, min;
};
signed main(){
    int T;
    cin >> T;
    while(T--){
        int N, K;
        vector<int> location(N);
        for(int i = 0; i<N; i++){
            cin >> location[i];
        }
        sort(location.begin(), location.end());
        //if possible to not cut overlap, don't cut overlap.
        vector<law> laws;
        for(int i = 0; i<K; i++){
            int a, b, c;
            cin >> a >> b >> c;
            laws[i] = {a, b, c};
        }
    }
}