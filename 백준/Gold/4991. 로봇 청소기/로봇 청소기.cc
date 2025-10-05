#include <iostream>
#include <queue>
using namespace std;

int w, h, sx, sy, target;
char map[20][21];
bool visited[20][20][1 << 10];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    visited[sx][sy][0] = true;

    int result = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int keys = q.front().second;
            q.pop();

            if (keys == target) {
                return result;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nkeys = keys;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    continue;
                }
                if (map[nx][ny] >= 'a' && map[nx][ny] <= 'j') {
                    nkeys |= 1 << (map[nx][ny] - 'a');
                }
                if (visited[nx][ny][nkeys] || map[nx][ny] == 'x') {
                    continue;
                }
                visited[nx][ny][nkeys] = true;
                q.push({{nx, ny}, nkeys});
            }
        }
        result++;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        char c = 'a';
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                if (map[i][j] == '*') {
                    map[i][j] = c++;
                }
                if (map[i][j] == 'o') {
                    sx = i; sy = j;
                }
            }
        }
        target = (1 << (c - 'a')) - 1;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k <= target; k++) {
                    visited[i][j][k] = false;
                }
            }
        }

        cout << bfs() << '\n';
    } 
    return 0;
}