#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int stair[301];
    int dp[2][301], n;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> stair[i];
    }

    dp[0][0] = 0;
    dp[1][0] = 0;

    dp[0][1] = stair[1];
    dp[1][1] = stair[1];

    for(int i = 2; i <= n; i++){
        dp[1][i] = stair[i] + dp[0][i - 1];
        dp[0][i] = stair[i] + max(dp[0][i - 2], dp[1][i - 2]);
    }

    cout << max(dp[0][n], dp[1][n]) << '\n';
}