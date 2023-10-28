#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> m1;
    string m2[100001], s;
    int N, M;

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> s;
        m1.insert(make_pair(s, i));
        m2[i] = s;
    }
    for(int i = 0; i < M; i++){
        cin >> s;
        if(s[0] >= 'A' && s[0] <= 'Z' || s[0] >= 'a' && s[0] <= 'z')
            cout << m1[s] << '\n';
        else
            cout << m2[stoi(s)] << '\n';
    }
} 