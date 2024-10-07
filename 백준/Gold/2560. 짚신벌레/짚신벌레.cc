#include <iostream>
using namespace std;

int a, b, d, N, dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> d >> N;

    dp[0] = 1;
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        if(i >= a) dp[i] = (dp[i] + dp[i - a]) % 1000;
        if(i >= b) dp[i] = (dp[i] - dp[i - b] + 1000) % 1000;
    }

    int result = dp[N];
    if(N >= d) {
        result = (result - dp[N - d] + 1000) % 1000;
    }
    cout << result << '\n';

    return 0;
}