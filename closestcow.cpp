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
vector<pair<int, int>> grasses, earlylate;
vector<int> pfx, Nhoj;
vector<inbetween> between;
signed main(){
    if(DEBUG){
        setIO("test");
    }
    else{
        setIO();
    }
    cin >> K >> M >> N;
    grasses.assign(K, {0, 0});
    pfx.assign(K, 0);
    Nhoj.assign(M, 0);
    between.assign(M+1, {0, 0, 0, 0});
    earlylate.assign(K, {0, 0});
    for(int i = 0; i<K; i++){
        int a, b;
        cin >> a >> b;
        grasses[i] = {a, b};
    }
    sort(grasses.begin(), grasses.end());
    pfx[0] = grasses[0].second;
    for(int i = 1; i<K; i++){
        pfx[i] = pfx[i-1] + grasses[i].second;
    }
    for(int i = 0; i<M; i++){
        cin >> Nhoj[i];
    }
    sort(Nhoj.begin(), Nhoj.end());
    vector<int> winnings;
    int runningtot = 0;
    int patches = 0;
    int begin = 0;
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
    begin = Nhoj[M-1];
    while(patches < K){
        runningtot += grasses[patches].second;
        patches++;
    }
    between[M] = {runningtot, begin, grasses[K-1].first, 1};
    for(int i = 0; i<M+1; i++){
        cout << between[i].val << " " << between[i].x << " " << between[i].y << " " << between[i].needed << endl;
    }
    //at most I need two places to cut an entire section for farmer john --> place a cow next to the two farmer nhoj ones that border the region
    //now I just need to determine the maximum I can win with one cow within a section
    //if i only place 1 --> it is best to claim closer towards the person who has more on their half --> FIGURE THIS OUT MORE
    //after doing that --> FIGURE IT OUT
    //find the rightmost point, leftmost point of collecting each patch
    for(int i = 0; i<K; i++){
        int leftmost, rightmost;
        if(grasses[i].first < Nhoj[0]){
            leftmost = 2*grasses[i].first - Nhoj[0]+1;
        }
        else{
            leftmost = 2 * grasses[i].first - Nhoj[upper_bound(Nhoj.begin(), Nhoj.end(), grasses[i].first) - Nhoj.begin()] + 1;
        }
        if(grasses[i].first > Nhoj[M-1]){
            rightmost = 2 * grasses[i].first - Nhoj[M-1] - 1;
        }
        else{
            rightmost = 2 * grasses[i].first - Nhoj[upper_bound(Nhoj.begin(), Nhoj.end(), grasses[i].first) - Nhoj.begin()-1] -1;
        }
        earlylate[i] = {leftmost, rightmost};

    } 
}