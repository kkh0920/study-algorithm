#include <iostream>
using namespace std;

int T, N, M, arr[21], dp[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while(T--){
        cin >> N;

        fill(dp, dp + (M + 1), 0);
        dp[0] = 1;

        for(int i = 1; i <= N; i++){
            cin >> arr[i];
        }

        cin >> M;

        for(int i = 1; i <= N; i++){
            for(int j = arr[i]; j <= M; j++){
                dp[j] += dp[j - arr[i]];
            }
        }

        cout << dp[M] << '\n';
    }
}
