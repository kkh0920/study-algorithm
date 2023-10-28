#include <iostream>
using namespace std;

int T, W, dp[1001][32];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T >> W;

    int num;

    for(int i = 1; i <= T; i++){
        cin >> num;
        for(int j = 0; j <= i && j <= W; j++){
            if(j % 2 == 0){ // 1에 있을 경우
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + (num == 1 ? 1 : 0));
                dp[i][j + 1] = dp[i - 1][j] + (num == 1 ? 0 : 1);
            }
            else{ // 2에 있을 경우
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + (num == 1 ? 0 : 1));
                dp[i][j + 1] = dp[i - 1][j] + (num == 1 ? 1 : 0);
            }
        }
    }

    int result = 0;
    for(int i = 0; i <= W; i++){
        result = max(result, dp[T][i]);
    }

    cout << result << '\n';
}