#include <bits/stdc++.h>
using namespace std;
#define int long long
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
vector<int> t;
vector<int> nums;
vector<bool> need;
void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = nums[tl];
    }
    else{
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1]; 
    }
}
void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        t[v] = new_val;
    }
    else{
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(v * 2, tl, tm, pos, new_val);
        }
        else{
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
int query(int v, int tl, int tr, int l, int r){
    if(l > r){
        return 0;
    }
    if(l == tl && r == tr){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int N, Q, C;
        cin >> N >> Q >> C;
        nums.assign(N, 0);
        need.assign(N, false);
        for(int i = 0; i<N; i++){
            cin >> nums[i];
            if(nums[i] == 0){
                need[i] = true;
            }
        }
        t.assign(4*N, 0);
        build(1, 0, N);

    }
}