#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> s;
    bool isBalanced, isEnd;
    string a = "";
    
    while(1){
        isEnd = true;
        isBalanced = true;
        getline(cin, a);
        for(int i = 0; a.size(); i++){
            if(a[i] == '.')
                break;
            isEnd = false;
            if(a[i] == '(' || a[i] == '[')
                s.push(a[i]);
            else if(a[i] == ')'){
                if(s.empty() || s.top() != '('){
                    isBalanced = false;
                    break;
                }
                s.pop();
            }
            else if(a[i] == ']'){
                if(s.empty() || s.top() != '['){
                    isBalanced = false;
                    break;
                }
                s.pop();
            }
        }
        if(isEnd)
            return 0;

        if(isBalanced && s.empty())
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';

        while(!s.empty())
            s.pop();
    }
}