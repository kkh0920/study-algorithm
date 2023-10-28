#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    deque<char> s;
    char str[500001];
    int N, K;

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> str[i];
        
        if(s.empty()){
            s.push_back(str[i]);
            continue;
        }

        while(!s.empty() && s.back() < str[i] && K){
            s.pop_back();
            K--;
        }

        s.push_back(str[i]);
    }

    while(K--){
        s.pop_back();
    }

    while(!s.empty()){
        cout << s.front();
        s.pop_front();
    }
    cout << '\n';
}