#include <bits/stdc++.h>
using namespace std;

//BOJ 2579
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


    // dp[0][i]는 dp[0][i - 2]와 dp[1][i - 2] 중 큰 값.
    //   -> 0번 인덱스는 현재 계단과 이전 계단 연결 X.
    //     -> 즉, 2단계 전의 계단을 비교. => 이 계단이 이것의 전 계단과 연결되어있는지는 따질 필요 없음.
    //        -> 3개의 계단이 연결 되지 않기 때문, 따라서 2단계 전 계단의 1번과 2번중 최댓값을 넣어줌.

    // dp[1][i]는 dp[0][i - 1]
    //   -> 1번 인덱스는 현재 계단과 이전 계단 연결.
    //     -> 즉, 이전 계단의 1번 인덱스를 값에 넣으면 계단 3개가 연결되므로, 조건 불일치.
    //        따라서 이전 계단의 1번 인덱스만 넣어줌.

    for(int i = 2; i <= n; i++){
        dp[1][i] = stair[i] + dp[0][i - 1];
        dp[0][i] = stair[i] + max(dp[0][i - 2], dp[1][i - 2]);
    }

    cout << max(dp[0][n], dp[1][n]) << '\n';
}