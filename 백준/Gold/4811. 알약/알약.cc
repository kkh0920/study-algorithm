#include <bits/stdc++.h>
using namespace std;

long long dp[60][31];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0][1] = 1;
    for(int i = 1; i < 60; i++){
        for(int j = 0; j <= i && j <= 30; j++){
            if(dp[i - 1][j] > 0){
                if(j > 0)
                    dp[i][j - 1] += dp[i - 1][j];
                if(j < 30)
                    dp[i][j + 1] += dp[i - 1][j];
            }
        }
    }

    int n;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        cout << dp[n * 2 - 1][0] << '\n';
    }
}