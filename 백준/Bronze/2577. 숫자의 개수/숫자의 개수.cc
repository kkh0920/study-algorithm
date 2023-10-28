#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int a, b, c, num, arr[10] = { 0, };

    cin >> a >> b >> c;

    num = a * b * c;
    s = to_string(num);

    for(int i = 0; i < s.length(); i++){
        arr[s[i] - 48]++;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << '\n';
    }
}