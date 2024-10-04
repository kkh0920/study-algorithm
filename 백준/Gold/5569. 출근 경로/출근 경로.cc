#include <iostream>
using namespace std;

int w, h, dp[2][2][101][101];

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

int solve(bool isRotate, int dir, int x, int y) {
    if(x > w || y > h) return 0;
    if(dp[isRotate][dir][x][y] != -1) return dp[isRotate][dir][x][y];

    if(isRotate) {
        return dp[isRotate][dir][x][y] = solve(false, dir, x + dx[dir], y + dy[dir]);
    }

    int rotateDir = dir == 0 ? 1 : 0;

    int straight = solve(false, dir, x + dx[dir], y + dy[dir]);
    int rotate = solve(true, rotateDir, x + dx[rotateDir], y + dy[rotateDir]);

    return dp[isRotate][dir][x][y] = (straight + rotate) % 100000;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> w >> h;

    for(int i = 1; i <= w; i++) {
        for(int j = 1; j <= h; j++) {
            dp[0][0][i][j] = -1; dp[0][1][i][j] = -1;
            dp[1][0][i][j] = -1; dp[1][1][i][j] = -1;
        }
    }
    dp[0][0][w][h] = 1; dp[1][0][w][h] = 1;
    dp[0][1][w][h] = 1; dp[1][1][w][h] = 1;

    if(w == 1 && h == 1) {
        cout << 1 << '\n';
    } else {
        cout << (solve(false, 0, 1, 2) + solve(false, 1, 2, 1)) % 100000 << '\n';
    }

    return 0;
}