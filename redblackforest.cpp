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
        //determine the number of trees we need to stand
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
vector<int> t;
void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = nums[tl];
    }
    else{
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1]; 
    }
}
void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        t[v] = new_val;
    }
    else{
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(v * 2, tl, tm, pos, new_val);
        }
        else{
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
int query(int v, int tl, int tr, int l, int r){
    if(l > r){
        return 0;
    }
    if(l == tl && r == tr){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}