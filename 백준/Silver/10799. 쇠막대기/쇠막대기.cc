#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<char> s;
    string str;
    char prev;
    int result = 0;

    getline(cin, str);

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(')
            s.push('(');
        if(str[i] == ')'){
            if(prev == ')'){
                s.pop();
                result++;
            }
            else{
                s.pop();
                result += s.size();
            }
        }
        prev = str[i];
    }

    cout << result << '\n';
}