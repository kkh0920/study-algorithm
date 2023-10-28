#include <bits/stdc++.h>
using namespace std;

int prior(char c){
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> s;
    string str;

    cin >> str;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(')
            s.push(str[i]);
        else if(str[i] == ')'){
            while(s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            while(!s.empty() && prior(str[i]) <= prior(s.top())){
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else
            cout << str[i];
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << '\n';
}