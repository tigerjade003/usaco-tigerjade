#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        string q;
        cin >> q;
        for(int i = 0; i<q.length(); i++){
            char Z = q[i];
            if(Z == 'A') cout << 'T';
            else if(Z == 'T') cout << 'A';
            else if(Z == 'C') cout << 'G';
            else cout << 'C';
        }
        cout << endl;
    }
}