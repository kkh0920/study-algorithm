#include <iostream>
#include <string.h>
using namespace std;

string str;
int dp[2501], pal_check[2501][2501];

bool is_palindrome(int from, int to) {
    if (pal_check[from][to] != 0) {
        return (pal_check[from][to] == 1);
    }
    while (from < to) {
        if (str[from] != str[to]) {
            pal_check[from][to] = -1;
            return false;
        }
        from++;
        to--;
    }
    pal_check[from][to] = 1;
    return true;
}

int solve(int from) {
    if (dp[from] != -1) {
        return dp[from];
    }

    int result = 2501;
    int len = str.length();
    for (int i = from; i < len; i++) {
        if (is_palindrome(from, i)) {
            result = min(result, 1 + solve(i + 1));
        }
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

    cout << solve(0) << '\n';

    return 0;
}