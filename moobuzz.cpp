#include <bits/stdc++.h>
using namespace std;
int N;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int main(){
    setIO("moobuzz");
    cin >> N;
    int last = 0;
    while(N != last){
        int k = N;
        N += N/3 + N/5 - N/15 - last/3 - last/5 + last/15;
        last = k;
    }
    cout << N << endl;
}