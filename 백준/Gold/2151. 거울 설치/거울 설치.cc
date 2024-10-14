#include <iostream>
using namespace std;

#define INF 99999999

int N, dp[50][50][4], result = INF;
char map[50][51];

bool visited[50][50];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isInside(int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < N);
}

void move(int x, int y, int dir, int num) {
    if(dp[x][y][dir] <= num) return;
    dp[x][y][dir] = num;

    visited[x][y] = true;

    int nx = x + dx[dir], ny = y + dy[dir];
    while(isInside(nx, ny) && map[nx][ny] != '*') {
        if(map[nx][ny] == '#') {
            result = min(result, num);
            break;
        }
        if(!visited[nx][ny] && map[nx][ny] == '!') {
            move(nx, ny, (dir + 1) % 4, num + 1);
            move(nx, ny, (dir + 3) % 4, num + 1);
        }
        nx += dx[dir];
        ny += dy[dir];
    }

    visited[x][y] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int x, y;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == '#') {
                x = i;
                y = j;
            }
            dp[i][j][0] = INF; dp[i][j][1] = INF;
            dp[i][j][2] = INF; dp[i][j][3] = INF;
        }
    }

    visited[x][y] = true;

    for(int dir = 0; dir < 4; dir++) {
        move(x, y, dir, 0);
    }

    cout << result << '\n';

    return 0;
}