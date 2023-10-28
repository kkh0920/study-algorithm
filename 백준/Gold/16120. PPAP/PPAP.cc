#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack< pair<char, int> > s;
    string str;

    cin >> str;

    for(int i = 0; i < str.length(); i++){
        if(s.empty()){
            if(str[i] == 'P')
                s.push(make_pair(str[i], 1));
            else{
                cout << "NP\n";
                return 0;
            }
            continue;
        }

        if(str[i] == 'P'){
            if(s.top().first == 'A'){
                for(int i = 0; i < 3; i++){
                    s.pop();
                }
            }
            int cnt;
            
            if(s.empty())
                cnt = 1;
            else
                cnt = s.top().second + 1;

            s.push(make_pair(str[i], cnt));
        }

        else if(s.top().first == 'A' || s.top().second < 2){
            cout << "NP\n";
            return 0;
        }

        else
            s.push(make_pair(str[i], 0));
    }

    if(s.top().first == 'P' && s.size() == 1)
        cout << "PPAP\n";
    else
        cout << "NP\n";
}   
