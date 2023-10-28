#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> m;
    string s, arr[500000];
    int N, M, idx = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> s;
        m.insert(make_pair(s, 1));
    }
    for(int i = 0; i < M; i++){
        cin >> s;
        if(m.find(s) != m.end())
            arr[idx++] = s;
    }
    
    sort(arr, arr + idx);
    
    cout << idx << '\n';
    for(int i = 0; i < idx; i++){
        cout << arr[i] << '\n';
    }
}