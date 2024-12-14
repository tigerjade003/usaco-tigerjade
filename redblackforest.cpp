#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int N;
struct law{
    int start, end, min;
};
signed main(){
    int T;
    cin >> T;
    while(T--){
        int N, K;
        vector<int> location(N);
        for(int i = 0; i<N; i++){
            cin >> location[i];
        }
        sort(location.begin(), location.end());
        //if possible to not cut overlap, don't cut overlap.
        vector<law> laws;
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
        map<int, int> new_old;
        vector<int> decompress;
        int index = 0;
        for(int co: coord){
            new_old[co] = index++;
            decompress.push_back(co);
        }
        int compress = decompress.size();
        
    }
}