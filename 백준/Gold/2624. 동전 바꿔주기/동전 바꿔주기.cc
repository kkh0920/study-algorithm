#include <iostream>
#include <vector>
using namespace std;

int T, k, dp[100][10001];
vector<pair<int, int>> coins;

int solve(int index, int amount) {
    if (amount == 0) {
        return 1;
    }
    if (index == k) {
        return 0;
    }
    if (dp[index][amount] != -1) {
        return dp[index][amount];
    }

    int coin = coins[index].first;
    int count = coins[index].second;

    dp[index][amount] = 0;
    for (int i = 0; i <= count; i++) {
        if (amount - coin * i < 0) {
            break;
        }
        dp[index][amount] += solve(index + 1, amount - coin * i);
    }

    return dp[index][amount];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T >> k;

    int p, n;
    for (int i = 0; i < k; i++) {
        cin >> p >> n;
        coins.push_back({p, n});
        for (int j = 1; j <= T; j++) {
            dp[i][j] = -1;
        }
    }

    cout << solve(0, T) << '\n';

    return 0;
}