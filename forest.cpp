#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

int T, N, K;
vector<int> locations;
vector<pair<int, pair<int, int>>> rules;
vector<int> prefix;
int main() {
    setIO();
    cin >> T;
    while (T--) {
        cin >> N >> K;
        locations.assign(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> locations[i];
        }
        rules.assign(K, {0, {0, 0}});
        for (int i = 0; i < K; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            rules[i] = {a, {b, c}};
        }
        sort(locations.begin(), locations.end());
        sort(rules.begin(), rules.end());
        set<int> compress(locations.begin(), locations.end());
        for (int i = 0; i < K; i++) {
            compress.insert(rules[i].first);
            compress.insert(rules[i].second.first);
        }
        vector<int> nums(compress.begin(), compress.end());
        map<int, int> maps;
        prefix.assign(compress.size() + 1, 0);
        for (int i = 0; i < compress.size(); i++) {
            maps[nums[i]] = i;
        }
        for (int i = 0; i < N; i++) {
            locations[i] = maps[locations[i]];
        }
        vector<int> needed(K, 0);
        for (int i = 0; i < K; i++) {
            rules[i].first = maps[rules[i].first];
            rules[i].second.first = maps[rules[i].second.first];
            prefix[rules[i].first]++;
            prefix[rules[i].second.first + 1]--;
            needed[i] = rules[i].second.second;
        }
        for(int i = 1; i<compress.size(); i++){
            prefix[i] += prefix[i-1];
        }
        int done = K;
        int kept = 0;
        vector<bool> planted(N, false);
        while(done != 0){
            int a = -1;
            for(int i = 1; i<N; i++){
                if(!planted[i] && (a == -1 || (prefix[locations[i]] > prefix[locations[a]]))){
                    a = i;
                }
            }
            planted[a] = true;
            kept++;
            bool needs = false;
            for(int i = 0; i<K; i++){
                if(locations[a] >= rules[i].first && locations[a] <= rules[i].second.first){
                    needed[i]--;
                    if(needed[i] == 0){
                        needs = true;
                        done--;
                    }
                }
            }
            if(needs){
                prefix.assign(compress.size() + 1, 0);
                for (int i = 0; i < K; i++) {
                    prefix[rules[i].first]++;
                    prefix[rules[i].second.first + 1]--;
                }
                for(int i = 1; i<compress.size(); i++){
                    prefix[i] += prefix[i-1];
                }
            }
        }
        cout << N-kept << endl;
    }
}
