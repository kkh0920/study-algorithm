#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, dp[100000] = { 1, 3, };

    cin >> N;

    for(int i = 2; i <= N; i++){
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
    }

    cout << dp[N] << '\n';
}