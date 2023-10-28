#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, dp[101][10];

    for(int i = 0; i <= 9; i++){
        dp[1][i] = 1;
    }
    
    cin >> N;

    for(int i = 2; i <= N; i++){
        dp[i][0] = dp[i - 1][1];
        for(int j = 1; j <= 8; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000; 
        }
        dp[i][9] = dp[i - 1][8];
    }
    
    int result = 0;
    for(int i = 1; i <= 9; i++){
        result += dp[N][i];
        result %= 1000000000;
    }

    cout << result << '\n';
}