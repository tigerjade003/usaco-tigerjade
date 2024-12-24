#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
//a = 97, z = 122, A = 65, Z = 92;
int main(){
    setIO();
    int T;
    cin >> T;
    while(T--){
        string a, b;
        cin >> a;
        cin >> b;
        vector<char> mapTo(52, 0);
        bool works = true;
        vector<bool> used(52, false);
        int count = 0;
        bool differ = 0;
        for(int i = 0; i<a.size(); i++){
            //lowercase a-z is 26-51
            //uppercase A-Z is 0-25
            int place = 0;
            if(a[i] >= 97){
                place = a[i] - 97 + 26; 
            }
            else{
                place = a[i] - 65;
            }
            if(mapTo[place] != 0 && mapTo[place] != b[i]){
                works = false;
                break;
            }
            else{
                int places = 0;
                if(b[i] >= 97){
                    places = b[i] - 97 + 26; 
                }
                else{
                    places = b[i] - 65;
                }
                if(!used[places]){
                    used[places] = true;
                    count++;
                }
                if(place != places){
                    differ = true;
                }
                mapTo[place] = places;
            }
        }
        if(!works || (count == 52 && differ)){
            cout << -1 << endl;
            continue;
        }
        
    }
}