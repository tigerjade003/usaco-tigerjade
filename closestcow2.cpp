#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define DEBUG false
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int K, M, N;
vector<pair<int, int>> patches;
vector<int> answer;
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    cin >> K >> M >> N;
    patches.assign(K+M, {0, 0});
    for(int i = 0; i<K; i++){
        int a, b;
        cin >> a >> b;
        patches[i] = {a, b};
    }
    for(int i = 0; i<M; i++){
        int a;
        cin >> a;
        patches[K+i] = {a, -1};
    }
    sort(patches.begin(), patches.end());
    int totsum = 0;
    int last = -1;
    for(int i = 0; i<patches.size(); i++){
        if(patches[i].second == -1){
            if(last == -1){
                answer.push_back(totsum);
            }
            else{
                int curans = 0;
                int bestans = 0;
                for (int j = last + 1, r = last; j < i; ++j) {
					while (r + 1 < i &&
						   (patches[r + 1].first - patches[j].first) * 2 < patches[i].first - patches[last].first) {
						curans += patches[++r].second;
					}
					bestans = max(bestans, curans);
					curans -= patches[j].second;
				}
                answer.push_back(bestans);
                answer.push_back(totsum - bestans);
            }
            totsum = 0;
            last = i;
        }
        else{
            totsum += patches[i].second;
        }
    }
    answer.push_back(totsum);
    sort(answer.rbegin(), answer.rend());
    int ans = 0;
    for(int i = 0; i<N; i++){
        ans += answer[i];
    }
    cout << ans << endl;
}