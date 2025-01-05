#include <bits/stdc++.h>
using namespace std;
#define int long long
#define DEBUG true
int K, M, N;
struct inbetween{
    int val, x, y, needed;
};
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
vector<pair<int, int>> grasses, bestof;
map<int, int> adds, removes;
set<int> check;
vector<int> Nhoj;
vector<inbetween> between;
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    cin >> K >> M >> N;
    grasses.assign(K, {0, 0});
    Nhoj.assign(M, 0);
    between.assign(M+1, {0, 0, 0, 0});
    for(int i = 0; i<K; i++){
        int a, b;
        cin >> a >> b;
        grasses[i] = {a, b};
    }
    sort(grasses.begin(), grasses.end());
    for(int i = 0; i<M; i++){
        cin >> Nhoj[i];
    }
    sort(Nhoj.begin(), Nhoj.end());
    vector<int> winnings;
    int runningtot = 0, patches = 0, begin = 0;
    for(int i = 0; i<M; i++){
        while(patches < K && grasses[patches].first < Nhoj[i]){
            runningtot += grasses[patches].second;
            patches++;
        }
        between[i] = {runningtot, begin, Nhoj[i], (i == 0? 1 : 2)};
        runningtot = 0;
        begin = Nhoj[i];
    }
    runningtot = 0;
    while(patches < K){
        runningtot += grasses[patches].second;
        patches++;
    }
    between[M] = {runningtot, Nhoj[M-1], grasses[K-1].first, 1};
    for(int i = 0; i<K; i++){
        int leftmost, rightmost;
        if(grasses[i].first < Nhoj[0]) leftmost = max(2*grasses[i].first - Nhoj[0]+1, 0LL);
        else leftmost = max(2 * grasses[i].first - Nhoj[upper_bound(Nhoj.begin(), Nhoj.end(), grasses[i].first) - Nhoj.begin()] + 1, Nhoj[upper_bound(Nhoj.begin(), Nhoj.end(), grasses[i].first) - Nhoj.begin()-1]+1);
        if(grasses[i].first > Nhoj[M-1]) rightmost = min(2 * grasses[i].first - Nhoj[M-1] - 1, 1000000000LL);
        else rightmost = min(2 * grasses[i].first - Nhoj[upper_bound(Nhoj.begin(), Nhoj.end(), grasses[i].first) - Nhoj.begin()-1] -1, Nhoj[upper_bound(Nhoj.begin(), Nhoj.end(), grasses[i].first) - Nhoj.begin()]-1);
        adds[leftmost]+= grasses[i].second;
        removes[rightmost+1]+= grasses[i].second;
        check.insert(leftmost);
        check.insert(rightmost);
    }
    int bestso = 0, before = -1, running = 0;
    for(int i: check){
        if(upper_bound(Nhoj.begin(), Nhoj.end(), i) != upper_bound(Nhoj.begin(), Nhoj.end(), before)){
            bestof.push_back({bestso, i});
            bestso = 0;
            running = 0;
        }
        running += adds[i] - removes[i];
        before = i;
        bestso = max(bestso, running);
    }
    bestof.push_back({bestso, *check.rend()});
    cout << endl;
    for(int i = 0; i<bestof.size(); i++){
        cout << bestof[i].first << " " << bestof[i].second <<endl;
    }
}