#include <iostream>
#include <string.h>
using namespace std;

string str;
int dp[2501];

bool is_palindrome(int from, int to) {
    while (from < to) {
        if (str[from++] != str[to--]) {
            return false;
        }
    }
    return true;
}

int solve(int from, int index) {
    if (dp[from] != -1) {
        return dp[from];
    }
    if (index >= str.length()) {
        return 2501;
    }

    int result = solve(from, index + 1);
    if (is_palindrome(from, index)) {
        result = min(result, 1 + solve(index + 1, index + 1));
    }

    return dp[from] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    memset(dp, -1, sizeof(dp));
    dp[str.length()] = 0;

    cout << solve(0, 0) << '\n';

    return 0;
}