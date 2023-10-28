#include <iostream>
using namespace std;

int N, dp[1500002], cost[1500002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // dp[n] -> n일 부터 상담을 시작했을 때 얻을 수 있는 최대 이익
    
    // 1. 오늘 상담을 하는 경우 -> value[n] + dp[1 + cost[n]] 
    // 2. 오늘 상담을 하지 않는 경우 -> dp[n + 1] 

    // dp[n] = max(value[n] + dp[n + cost[n]], dp[n + 1])

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> cost[i] >> dp[i];
    }

    for(int i = N; i >= 1; i--){
        if(i + cost[i] > N + 1)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(dp[i] + dp[i + cost[i]], dp[i + 1]);
    }

    cout << dp[1] << '\n';
}
