#include <iostream>
using namespace std;

const int INF = 1e9;

int N, M, map[1000][1000], dp[3][1000][1000];
bool visited[1000][1000];

// dir -> 0: left, 1: right, 2: down
int maxValueFrom(int dir, int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M || visited[x][y]) {
        return -INF;
    }
    if (dp[dir][x][y] != INF) {
        return dp[dir][x][y];
    }
    
    visited[x][y] = true;

    int result = map[x][y] + max(
        max(
            maxValueFrom(0, x, y - 1), // left move
            maxValueFrom(1, x, y + 1) // right move
        ),
        maxValueFrom(2, x + 1, y) // down move
    );

    visited[x][y] = false;

    return dp[dir][x][y] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            dp[0][i][j] = INF;
            dp[1][i][j] = INF;
            dp[2][i][j] = INF;
        }
    }
    dp[1][N - 1][M - 1] = map[N - 1][M - 1];
    dp[2][N - 1][M - 1] = map[N - 1][M - 1];

    cout << maxValueFrom(1, 0, 0) << '\n';

    return 0;
}