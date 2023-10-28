#include <iostream>
using namespace std;

int N, K, dp[1001][10001];
int val[1001], cost[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i <= K; i++){
        cin >> val[i] >> cost[i];
    }

    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= N; j++){
            if(j - cost[i] >= 0)
                dp[i][j] = max(dp[i - 1][j - cost[i]] + val[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[K][N] << '\n';
}