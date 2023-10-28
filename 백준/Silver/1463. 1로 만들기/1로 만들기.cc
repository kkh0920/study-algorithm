#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, dp[1000001] = { 0, 0, 1, 1, };

    cin >> n;

    for(int i = 4; i <= n; i++){
        int next = 99999;
        if(i % 3 == 0)
            next = min(next, dp[i / 3]);
        if(i % 2 == 0)
            next = min(next, dp[i / 2]);
        next = min(next, dp[i - 1]);
        dp[i] = next + 1;
    }
    
    cout << dp[n] << '\n';
}