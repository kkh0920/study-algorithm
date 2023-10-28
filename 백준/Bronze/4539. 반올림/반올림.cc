#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string s;

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s;
        for(int i = s.length() - 1; i >= 1; i--){
            if(s[i] >= '5'){
                s[i - 1]++;
            }
            s[i] = '0';
        }
        if(s[0] == ':'){
            s[0] = '0';
            cout << '1';
        }
        cout << s << '\n';
    }
}