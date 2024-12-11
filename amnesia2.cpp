#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string q;
    cin >> q;
    if(q == "START"){
        cout << 111111;
    }
    else if(q == "OBSERVE"){
        cin >> N;
        char q;
        cin >> q;
        if(q == 'G'){
            N += 1000;
        }
        else if(q == 'S'){
            N++;
        }
        cout << N;
    }
    else{
        cin >> N;
        int S = (N % 1000) - 111;
        int G = (N/1000) - 111;
        char most = '_';
        char mid = '_';
        char least = '_';
        if(S > 200){
            most = 'S';
        }
        else if(S > 100){
            mid = 'S';
        }
        else{
            least = 'S';
        }
        if(G > 200){
            most = 'G';
        }
        else if(G > 100){
            mid = 'G';
        }
        else{
            least = 'G';
        }
        cout << (least == '_' ? 'B' : least) << (mid == '_' ? 'B' : mid) << (most == '_' ? 'B' : most);
    }
}