#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    list<char> str;
    int t;
    
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s;
        list<char>::iterator cursor;
        for(int j = 0; j < s.length(); j++){
            switch (s[j]){
            case '<':
                if(str.empty() || cursor == str.begin())
                    break;
                cursor--;
                break;
            case '>':
                if(str.empty() || cursor == str.end())
                    break;
                cursor++;
                break;
            case '-':
                if(str.empty() || cursor == str.begin())
                    break;
                cursor = str.erase(--cursor);
                break;
            default:
                if(str.empty()){
                    str.push_back(s[j]);
                    cursor = str.end();
                    break;
                }
                str.insert(cursor, s[j]);
                break;
            }
        }
        for(auto x : str){
            cout << x;
        }
        cout << '\n';
        str.clear();
    }
}