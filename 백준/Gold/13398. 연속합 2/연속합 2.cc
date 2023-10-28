#include <bits/stdc++.h>
using namespace std;

int N, arr[100000], dp[2][100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    dp[0][0] = arr[0];
    dp[1][0] = 0;

    int result = arr[0];
    for(int i = 1; i < N; i++){
        dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]);
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + arr[i]);

        result = max(result, max(dp[0][i], dp[1][i]));
    }

    cout << result << '\n';
}