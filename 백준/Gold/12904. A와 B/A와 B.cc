#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    char arr[1001];

    cin >> s >> t;

    while(s.length() < t.length()){
        if(*(t.end() - 1) != 'B'){
            t.erase(t.end() - 1);
            continue;
        }

        t.erase(t.end() - 1);

        int idx = 0, len = t.length();
        for(int i = len - 1; i >= 0; i--){
            arr[idx++] = t[i];
        }
        t.clear();
        
        for(int i = 0; i < len; i++){
            t += arr[i];
        }
    }

    if(s == t)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

}