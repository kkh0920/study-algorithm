#include <iostream>
using namespace std;

int N = 0, arr[100000], dp[5][5][100000];
int cost[5][5] = {
    {0, 2, 2, 2, 2},
    {0, 1, 3, 4, 3},
    {0, 3, 1, 3, 4},
    {0, 4, 3, 1, 3},
    {0, 3, 4, 3, 1}
};

int solve(int left, int right, int index) {
    if(index == N) return 0;
    if(dp[left][right][index] != 0) return dp[left][right][index];

    int moveLeft = cost[left][arr[index]] + solve(arr[index], right, index + 1);
    int moveRight = cost[right][arr[index]] + solve(left, arr[index], index + 1);

    return dp[left][right][index] = min(moveLeft, moveRight);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(1) {
        cin >> n;
        if(n == 0) break;
        arr[N++] = n;
    }

    cout << solve(0, 0, 0) << '\n';

    return 0;
}