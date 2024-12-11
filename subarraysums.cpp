#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define int long long
struct subarr{
    int start, end, sum;
};
int N;
vector<int> nums;
int main(){
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
            subarrs[last] = subarr();
            subarrs[last].start = i;
            subarrs[last].start = j;
            subarrs[last].start = totsum;
            last++;
        }
    }
    sort(subarrs.begin(), subarrs.end(), [](const subarr&a, const subarr&b){
        return (a.sum < b.sum);
    });
    for(int i = 0; i<N; i++){
        int last = 1e15;
        bool hasit = (subarrs[0].start <=i &&  subarrs[0].end >= i);
        for(int j = 1; j<subarrs.size(); j++){
            bool cur = (subarrs[j].start <= i &&  subarrs[j].end >= i);
            if(cur != hasit){
                cur = hasit;
                last = min(last, abs(subarrs[j].sum - subarrs[j-1].sum));
            }
        }
        cout << last;
        if(i < N-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}