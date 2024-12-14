#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int n, k;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int main() {
    setIO();
    cin >> n >> k;
    vector<int> nums(n);
    vector<vector<bool>> cangoto(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        nums[i] = i;
        cangoto[i][i] = true;
    }
    vector<int> sizes(n, 1);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(!cangoto[nums[a]][b]){
            sizes[nums[a]]++;
        }
        if(!cangoto[nums[b]][a]){
            sizes[nums[b]]++;
        }
        swap(nums[a], nums[b]);
    }
    bool changed = true;
    while (changed) {//O(N)
        changed = false;
        for (int i = 0; i < n; i++) {//O(N)
            for (int j : cangoto[i]) {//O(N)
            if(cangoto[nums[i]][j] == false){
                changed = true;
                cangoto[nums[i]][j] = true;
                sizes[nums[i]]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << sizes[i] << endl;
    }
    return 0;
}
