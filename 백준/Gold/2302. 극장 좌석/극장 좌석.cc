#include <iostream>
using namespace std;

int N, M, dp[41][3][2];

int solve(int number, int seat_position, bool current_checked) {
    if (dp[number][seat_position][current_checked] != -1) {
        return dp[number][seat_position][current_checked];
    }

    int result = solve(number - 1, 0, seat_position == 0 ? true : false);

    if (seat_position != 0) {
        result += solve(number - 1, 1, true);
    }

    if (seat_position != 1 && !current_checked) {
        result += solve(number - 1, 2, seat_position == 0 ? true : false);
    }

    return dp[number][seat_position][current_checked] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dp[1][0][true] = 0; dp[1][0][false] = 0;
    dp[1][1][true] = 1; dp[1][1][false] = 1;
    dp[1][2][true] = 1; dp[1][2][false] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    int vip_number;
    for (int i = 0; i < M; i++) {
        cin >> vip_number;
        dp[vip_number][0][true] = 0; dp[vip_number][0][false] = 0;
        dp[vip_number][2][true] = 0; dp[vip_number][2][false] = 0;
    }

    cout << solve(N, 0, false) + solve(N, 1, true) << '\n';

    return 0;
}