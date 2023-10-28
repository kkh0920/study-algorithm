#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, dp[101][100001];
    pair<int, int> arr[101];

    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> arr[i].first >> arr[i].second;
        dp[i][0] = 0;
    }

    for(int i = 0; i <= K; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            int curW = arr[i].first;
            int curV = arr[i].second;
            if(curW > j){
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - curW] + curV);
        }
    }

    cout << dp[N][K] << '\n';
}