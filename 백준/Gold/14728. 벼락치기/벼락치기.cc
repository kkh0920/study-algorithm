#include <iostream>
#include <vector>
using namespace std;

int N, T, K[100], S[100], mem[100][10001];

int dp(int index, int time) {
    if (time < 0) {
        return -1e9;
    }
    if (index == N) {
        return 0;
    }
    if (mem[index][time] != -1) {
        return mem[index][time];
    }
    return mem[index][time] = max(
        dp(index + 1, time),
        dp(index + 1, time - K[index]) + S[index]
    );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        cin >> K[i] >> S[i];
        for (int j = 0; j <= T; j++) {
            mem[i][j] = -1;
        }
    }

    cout << dp(0, T) << '\n';

    return 0;
}