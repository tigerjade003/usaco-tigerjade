#include <bits/stdc++.h>
using namespace std;
#define int long long
int M = 1e9 + 9;
int P = 9973;
string a, b;
vector<int> lexigrapha;
vector<int> lexigraphb;
signed main(){
    cin >> a;
    cin >> b;
    while(a.length() < b.length()) a += " ";
    while(b.length() < a.length()) b += " ";
    lexigrapha.assign(a.size(), 0);
    lexigraphb.assign(b.size(), 0);
    int ans = 0;
    for(int i = 0; i<a.length(); i++){
        ans *= P;
        ans += a[i];
        ans %= M;
        lexigrapha[i] = ans;
    }
    ans = 0;
    for(int i = 0; i<b.length(); i++){
        ans *= P;
        ans += b[i];
        ans %= M;
        lexigraphb[i] = ans;
    }
    int l = 0;
    int h = lexigrapha.size() - 1;
    bool isontop = false;
    while(h > l){
        int mid = (l + h)/2;
        if(lexigrapha[mid] == lexigraphb[mid]){
            l = mid+1;
        }
        else{
            if(lexigrapha[mid] > lexigraphb[mid]){
                isontop = false;
            }
            else{
                isontop = true;
            }
            h = mid;
        }
    }
    cout << (isontop? a : b);
    return 0;
}