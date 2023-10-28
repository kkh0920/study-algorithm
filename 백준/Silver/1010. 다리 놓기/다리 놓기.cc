#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[31][31];

    for(int i = 1; i <= 29; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1)
                dp[i][j] = i;
            else
                dp[i][j] = dp[i][j - 1] * (i - j + 1) / j;
        }   
    }

    int t, n, m;
    
    cin >> t;
    
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
}