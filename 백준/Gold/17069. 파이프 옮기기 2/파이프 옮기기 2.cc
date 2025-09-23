#include <iostream>
using namespace std;

long long N, dp[32][32][3];
bool is_wall[32][32];

bool is_valid(int x, int y, int dir) {
    if (x >= N || y >= N || is_wall[x][y]) {
        return false;
    }
    if (dir == 2 && (is_wall[x - 1][y] || is_wall[x][y - 1])) {
        return false;
    }
    return true;
}

long long solve(int x, int y, int dir) {
    if (!is_valid(x, y, dir)) {
        return 0;
    }
    if (dp[x][y][dir] != -1) {
        return dp[x][y][dir];
    }

    dp[x][y][dir] = solve(x + 1, y + 1, 2);
    if (dir != 1) {
        dp[x][y][dir] += solve(x, y + 1, 0);
    }
    if (dir != 0) {
        dp[x][y][dir] += solve(x + 1, y, 1);
    }
    
    return dp[x][y][dir];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> is_wall[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
        }
    }
    dp[N - 1][N - 1][0] = dp[N - 1][N - 1][1] = dp[N - 1][N - 1][2] = 1;

    cout << solve(0, 1, 0) << '\n';

    return 0;
}