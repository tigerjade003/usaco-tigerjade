#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int main(){
    setIO("test");
    int N, totpost;
    cin >> N;
    vector<int> curs(N);
    for(int i = 0; i<N; i++){
        cin >> curs[i];
        totpost += curs[i];
    }
    vector<vector<bool>> adj(N, vector<bool>(N, false));
    for (int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = true;
        adj[b][a] = true;
    }
    bool works = true;
    int K;
    cin >> K;
    for(int i = 0; i<N; i++){
        int a, b, x;
        cin >> a >> b >> x;
        cout << a << " " << b << endl;
        if(adj[a-1][b-1] && curs[a-1] >= x){
            if(curs[a-1]>=x){
                curs[a-1] -= x;
                curs[b-1] +=x;
            }
        }
        else{
            cout << a << " " << b << " " << x << " " << adj[a-1][b-1] << " " << curs[a-1] << endl; 
            works = false;
            break;
        }
    }
    for(int i = 0; i<N; i++){
        if(curs[i] != totpost/N){
            works = false;
            break;
        }
    }
    cout << (works ? "YES" : "NO");
}