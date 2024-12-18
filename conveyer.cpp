#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<bool>> escapable;
int N, Q;
struct belt{
    int x, y;
};
int main(){
    cin >> N >> Q;
    grid.assign(N, vector<char>(N, '?'));
    escapable.assign(N, vector<bool>(N, false));
    for(int i = 0; i<Q; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        
    }

}