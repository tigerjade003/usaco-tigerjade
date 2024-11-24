#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string absent = "";
        cin >> absent;
        vector<string> listofPeople;
        vector<bool> returned;
        listofPeople.push_back(absent);
        returned.push_back(false);
        int n;
        cin >> n;
        for(int i = 0; i<n; i++){
            //<A> TURNS IN <B>'s BOOK
            string a;
            cin >> a;
            int found = -1;
            for(int i = 0; i<listofPeople.size(); i++){
                if(a == listofPeople[i]){
                    found = i;
                    break;
                }
            }
            if(found == -1){
                listofPeople.push_back(a);
                returned.push_back(false);
            }
            cin >> a;
            cin >> a;
            cin >> a;
            a.erase(remove(a.begin(), a.end(), ' '), a.end());
            a = a.substr(0, a.length() - 2);
            found = -1;
            for(int i = 0; i<listofPeople.size(); i++){
                if(a == listofPeople[i]){
                    found = i;
                    returned[i] = true;
                    break;
                }
            }
            if(found == -1){
                listofPeople.push_back(a);
                returned.push_back(true);
            }
            cin >> a;
        }
        int missing = 0;
        for(int i = 0; i<returned.size(); i++){
            if(!returned[i]){
                missing = i;
                break;
            }
        }
        cout << absent << " HAS " << listofPeople[missing] << "'s BOOK" << endl;
    }
}