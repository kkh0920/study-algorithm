#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, dp[31] = { 1, 0, 3, 0, 11, };

    cin >> N;

    if(N % 2 == 1){
        cout << 0 << '\n';
        return 0;
    }

    for(int i = 6; i <= N; i++){
        dp[i] = dp[i - 2];
        for(int j = i - 2; j >= 0; j-=2){
            dp[i] += 2 * dp[j];
        }
    }

    cout << dp[N] << '\n';
}