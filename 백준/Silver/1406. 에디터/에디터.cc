#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    list<char> str;
    string s;
    char c1, c2;
    int m;
    bool isFront = false;

    cin >> s >> m;

    for(int i = 0; i < s.length(); i++){
        str.push_back(s[i]);
    }

    list<char>::iterator cursor = str.end();

    for(int i = 0; i < m; i++){
        cin >> c1;
        switch (c1){
        case 'L':
            if(cursor != str.begin())
                cursor--;
            break;
        case 'D':
            if(cursor != str.end())
                cursor++;
            break;
        case 'B':
            if(cursor != str.begin())
                cursor = str.erase(--cursor);
            break;
        case 'P':
            cin >> c2;
            str.insert(cursor, c2);
            break;
        }
    }

    for(auto x : str){
        cout << x;
    }
    cout << '\n';
}