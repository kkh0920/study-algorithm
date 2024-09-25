#include <iostream>
using namespace std;

int n, m, dp[1000][1000];
int nameLen[1000];

int solve(int line, int index) {
    if(dp[line][index] != -1) {
        return dp[line][index];
    }
        
    int remain = m - nameLen[index], curIdx = index + 1;
    int result = 1000000001;
    while(nameLen[curIdx] + 1 <= remain && curIdx < n) {
        result = min(result, (remain * remain) + solve(line + 1, curIdx));
        remain -= nameLen[curIdx] + 1;
        curIdx++;
    }

    if(curIdx >= n) return dp[line][index] = 0;

    result = min(result, (remain * remain) + solve(line + 1, curIdx));

    return dp[line][index] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> nameLen[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    cout << solve(0, 0) << '\n';

    return 0;
}