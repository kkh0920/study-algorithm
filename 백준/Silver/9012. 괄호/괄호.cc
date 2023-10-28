#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    queue<char> q;
    int n, c = 0;
    string temp;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        for(int j = 0; j < temp.length(); j++){
            q.push(temp[j]);
        }
        while(q.size() != 0){
            if(q.front() == '('){
                c++;
                q.pop();
            }
            else{
                c--;
                q.pop();
            }
            if(c < 0)
                break;
        }
        while(q.size() != 0){
            q.pop();
        }
        if(c == 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        c = 0;
    }
}