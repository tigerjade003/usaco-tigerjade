#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define int long long
struct subarr{
    int start, end, sum;
};
int N;
vector<int> nums;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
signed main(){
    setIO();
    cin >> N;
    nums.assign(N, 0);
    for(int i = 0; i<N; i++){
        cin >> nums[i];
    }
    vector<subarr> subarrs((N*(N+1))/2);
    int last = 0;
    int totsum = 0;
    for(int i = 0; i<N; i++){
        totsum = 0;
        for(int j = i; j<N; j++){
            totsum += nums[j];
            subarrs[last] = {i, j, totsum};
            last++;
        }
    }
    sort(subarrs.begin(), subarrs.end(), [](const subarr&a, const subarr&b){
        return (a.sum < b.sum);
    });
    /*
    for(int i = 0; i<subarrs.size(); i++){
        cout << subarrs[i].start << " " << subarrs[i].end << " " << subarrs[i].sum << endl;
    }*/
    for(int i = 0; i<N; i++){
        int last = 1e15;
        bool hasit = (subarrs[0].start <=i &&  subarrs[0].end >= i);
        int lastsum = subarrs[0].sum;
        for(int j = 1; j<subarrs.size(); ++j){
            bool cur = (subarrs[j].start <= i &&  subarrs[j].end >= i);
            if(cur != hasit){
                hasit = !hasit;
                last = min(last, abs(subarrs[j].sum - lastsum));
            }
            lastsum = subarrs[j].sum;
        }
        cout << last << endl;
    }
    return 0;
}