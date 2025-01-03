#include <bits/stdc++.h>
using namespace std;
#define DEBUG true
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
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> q;
    int lookat = 0;
    int bcount = 0;
    pfxsum.assign(q.size(), 0);
    numsof.assign(q.size(), 0);
    for(int i = 0; i<q.size(); i++){
        if(q[i] == bessie[lookat]){
            lookat++;
            if(lookat == 6){
                bcount++;
                lookat = 0;
            }
        }
        numsof[i] = bcount;
        pfxsum[i] = bcount;
        cout << bcount << " ";
    }
    cout << endl;
    for(int i = 1; i<q.size(); i++){
        pfxsum[i] += pfxsum[i-1];
    }
    const char* looks = q.c_str();
    for(int i = 0; i<q.size(); i++){
        //assuming we exclude the character, can we still find a b, e, s, s, i, before we find our e that starts the new one?
        int lastpos = lower_bound(numsof.begin(), numsof.end(), numsof[i]+1) - numsof.begin();
        if(lastpos == numsof.size()) lastpos--;
        
    }

}