#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i<T; i++){
        string q;
        while(true){
            char z;
            cin >> z;
            if(z != ':'){
                q += z;
            }
            else{
                break;
            }
        }
        string e;
        while(true){
            char z;
            cin >> z;
            e += z;
            if(z == '.'){
                char a, b;
                cin >> a;
                cin >> b;
                e += a;
                e += b;
                break;
            }
        }
        double A = stod(q);
        double B = stod(e);
        if(B/A <= 1.00) cout << "SWERVE";
        else if(B/A <= 5.00) cout << "BRAKE";
        else cout << "SAFE";
        cout << endl;
    }
}