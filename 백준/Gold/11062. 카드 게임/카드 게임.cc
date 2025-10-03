#include <iostream>
using namespace std;

int T, N, score[1000], dp[1000][1000];

int solve1(int left, int right);
int solve2(int left, int right);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> score[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = 0;
            }
        }
        cout << solve1(0, N - 1) << "\n";
    }

    return 0;
}

int solve1(int left, int right) {
    if (left > right) {
        return 0;
    }
    if (dp[left][right] != 0) {
        return dp[left][right];
    }
    
    int result = max(
        score[left] + solve2(left + 1, right),
        score[right] + solve2(left, right - 1)
    );

    return dp[left][right] = result;
}

int solve2(int left, int right) {
    if (left > right) {
        return 0;
    }
    
    return min(
        solve1(left + 1, right),
        solve1(left, right - 1)
    );
}