#include <bits/stdc++.h>
using namespace std;
int n, k;
int main(){
    cin >> n >> k;
    vector<int> nums(n, 0);
    for(int i = 0; i<n; i++){
        nums[i] = i;
    }
    vector<set<int>> cangoto(n, set<int>());
    for(int i = 0; i<n; i++){
        cangoto[i].emplace(i);
    }
    for(int i = 0; i<k; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int temp;
        temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        cangoto[nums[a]].emplace(b);
        cangoto[nums[b]].emplace(a);
    }
    int count = n;
    vector<bool> istrue(n, true);
    vector<int> cur(n, 0);
    for(int i = 0; i<n; i++){
        cur[i] = nums[i];
    }
    vector<int> lastsize(n, 0);
    for(int i = 0; i<n; i++){
        lastsize[i] = cangoto[i].size();
    }
    while(count > 0){
        vector<int> curs(n, 0);
        for(int j = 0; j<n; j++){
            curs[j] = cur[nums[j]];
            if(istrue[cur[j]]){
                cangoto[curs[j]].insert(cangoto[j].begin(), cangoto[j].end());
                if(cangoto[curs[j]].size() == lastsize[curs[j]]){
                    istrue[curs[j]] = false;
                    count--;
                }
                else{
                    lastsize[curs[j]] = cangoto[curs[j]].size();
                }
            }
        }
        cur = curs;
    }
    for(int i = 0; i<n; i++){
        cout << cangoto[i].size() << endl;
    }   
}