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
vector<int> numsof;
vector<int> pfxsum;
vector<char> bessie{'b', 'e', 's', 's', 'i', 'e'};
int findnext(int start, int end, char find){
    for(int i = start; i<=end; i++){
        if(q[i] == find) return i;
    }
    return -1;
}
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> q;
    int ans = 0;
    vector<int> waiting(7, 0);
    int rem = q.size();
    for(char letter: q){
        waiting[0]++;
        for (int d = 5; d >= 0; d--) {
            if(letter == bessie[d]){
                waiting[d + 1] += waiting[d];
                waiting[d] = 0;
            }
        }
        ans += waiting[6] * rem;
        waiting[0] += waiting[6];
        waiting[6] = 0;
        rem--;
    }
    cout << ans << endl;
}