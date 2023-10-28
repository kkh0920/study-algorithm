#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[26] = { 0, };
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        arr[s[i] - 97]++;
    }
    for(int i = 0; i < 26; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}