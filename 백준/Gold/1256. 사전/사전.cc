#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

vector<char> result;
int dp[101][101];

void print(int n, int m) {
    for(auto c : result) {
        cout << c;
    }
    for(int i = 0; i < m; i++) {
        cout << 'z';
    }
    for(int i = 0; i < n; i++) {
        cout << 'a';
    }
    cout << '\n';
}

int solve(int prev, int n, int m) {
    if(dp[n][m] != -1 && prev + dp[n][m] < K) {
        return dp[n][m];
    }
    if(prev + dp[n][m] == K) {
        print(n, m);
        exit(0);
    }

    result.push_back('a');
    int a = solve(prev, n - 1, m);
    result.pop_back();

    result.push_back('z');
    int z = solve(prev + a, n, m - 1);
    result.pop_back();

    return dp[n][m] = a + z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            if(i == 0 || j == 0) dp[i][j] = 1;
            else dp[i][j] = -1;
        }
    }

    solve(0, N, M);

    cout << -1 << '\n';

    return 0;
}