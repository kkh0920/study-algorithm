#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[10] = { 0, };
    string s;

    cin >> s;

    for(int i = 0; i < s.length(); i++){
        arr[s[i] - 48]++;
    }

    int max = (arr[6] + arr[9]) / 2;
    max += (arr[6] + arr[9]) % 2 != 0 ? 1 : 0;

    for(int i = 0; i < 10; i++){
        if(i == 6 || i == 9)
            continue;
        max = arr[i] > max ? arr[i] : max;
    }
    
    cout << max << '\n';
}