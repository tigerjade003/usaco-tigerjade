#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
struct law{
    int start, end, min;
};
signed main(){
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        vector<int> location(N);
        for(int i = 0; i<N; i++){
            cin >> location[i];
        }
        sort(location.begin(), location.end());
        vector<law> laws(K);
        for(int i = 0; i<K; i++){
            int a, b, c;
            cin >> a >> b >> c;
            laws[i] = {a, b, c};
        }
        sort(laws.begin(), laws.end(), [](const law&a, const law&b){
            if(a.start != b.start) return a.start < b.start;
            else if(a.end < b.end) return a.end < b.end;
            else return a.min < b.min;
        });
        set<int> coord(location.begin(), location.end());
        for(int i = 0; i<K; i++){
            coord.insert(laws[i].start);
            coord.insert(laws[i].end);
        }
        map<int, int> news;
        vector<int> decompress;
        int index = 0;
        for(int co: coord){
            news[co] = index++;
            decompress.push_back(co);
        }
        int compress = decompress.size();
        for(int i = 0; i<N; i++){
            location[i] = news[location[i]];
        }
        for(int i = 0; i<K; i++){
            laws[i].start = news[laws[i].start];
            laws[i].end = news[laws[i].end];
        }
        vector<int> prefixss(compress+1, 0);
        for(int i = 0; i<K; i++){
            prefixss[laws[i].start]++;
            prefixss[laws[i].end+1]--;
        }
        for(int i = 1; i<compress+1; i++){
            prefixss[i] = prefixss[i-1] + prefixss[i];
        }
        for(int i = 0; i<compress+1; i++){
            cout << prefixss[i] << " ";
        }
        vector<pair<int, int>> needtrees(N); //number, position
        for(int i = 0; i<N; i++){
            needtrees[i] = {prefixss[location[i]], location[i]};
        }
        int needed = 0;

    }
}
