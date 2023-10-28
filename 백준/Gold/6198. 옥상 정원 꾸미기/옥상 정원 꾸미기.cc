#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    stack<int> s;

    cin >> N;

    int num;
    long long result = 0;
    for(int i = 0; i < N; i++){
        cin >> num;    

        if(s.empty()){
            s.push(num);
            continue;
        }

        while(!s.empty() && num >= s.top()){
            s.pop();
        }

        result += s.size();

        s.push(num);
    }

    cout << result << '\n';
}