#include <iostream>
using namespace std;

int N, M, w[1000], dp[20001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> w[i];
    }

    fill(dp, dp + 20001, 987654321);

    for(int i = 0; i < M; i++){
        for(int j = i; j < M; j++){
            if(i == j)
                dp[w[i]] = 1;
            else
                dp[w[i] + w[j]] = 1;
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i / 2; j++){
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
        }
    }

    if(dp[N] == 987654321)
        cout << -1 << '\n';
    else
        cout << dp[N] << '\n';
}
