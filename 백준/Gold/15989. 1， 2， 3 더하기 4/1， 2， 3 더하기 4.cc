#include <iostream>
using namespace std;

int T, n;
int dp[10001][3];

int dfs(int num, int start) {
    if(dp[num][start]) return dp[num][start];
    if(num == 0) return 1;

    int result = 0;
    for(int i = start; i <= 3; i++) {
        if(num - i >= 0) {
            result += dfs(num - i, i);
        }
    }

    return dp[num][start] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> n;
        cout << dfs(n, 1) << '\n';
    }

    return 0;
}