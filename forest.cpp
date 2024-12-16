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
bool works(int canuse, int size){
    int work = 0;
    vector<int> prefix(size, 0);
    vector<int> work(size, 0);
    for(int i = 0; i<K; i++){
        int thereare = prefix[rules[i].second.first] - prefix[rules[i].first];
        int needed = rules[i].second.second - thereare;
        canuse -= needed;
        if(canuse < 0) return false;
        //each time i plant a tree, work[i] increases. Then after planting them all I add the updates to prefix.
        for(int j = rules[i].second.first; j >= )
    }
}
int main(){
    setIO();
    cin >> T;
    while(T--){
        cin >> N >> K;
        locations.assign(N, 0);
        for(int i = 0; i<N; i++){
            cin >> locations[i];
        }
        rules.assign(K, {0, {0, 0}});
        for(int i = 0; i<K; i++){
            int a, b, c;
            cin >> a >> b >> c;
            rules[i] = {a, {b, c}};
        }
        sort(locations.begin(), locations.end());
        sort(rules.begin(), rules.end());
        set<int> compress(locations.begin(), locations.end());
        for(int i = 0; i<K; i++){
            compress.insert(rules[i].first);
            compress.insert(rules[i].second.first);
        }
        vector<int> nums(compress.begin(), compress.end());
        map<int, int> maps;
        for(int i = 0; i<compress.size(); i++){
            maps[nums[i]] = i;
        }
        for(int i = 0; i<N; i++){
            locations[i] = maps[locations[i]];
        }
        for(int i = 0; i<K; i++){
            rules[i].first = maps[rules[i].first];
            rules[i].second.first = maps[rules[i].second.first];
        }
        int min = 1, max = N, answer = 0;
        while(min <= max){
            int mid = (max  + min)/2;
            if(works(mid, compress.size())){
                max = mid-1;
                answer = mid;
            }
            else{
                min = mid+1;
            }
        }
        cout << N - answer << endl;
    }
}