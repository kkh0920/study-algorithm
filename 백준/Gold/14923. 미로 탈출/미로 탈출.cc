#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, bool>> q;
bool map[1001][1001], visited[1001][1001][2];
int N, M, Hx, Hy, Ex, Ey;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs() {
    q.push({{Hx, Hy}, false});
    visited[Hx][Hy][0] = true;
    
    int result = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            bool breaked = q.front().second;
            q.pop();

            if (x == Ex && y == Ey) {
                return result;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                bool nb = breaked;
                if (nx < 1 || nx > N || ny < 1 || ny > M) {
                    continue;
                }
                if (map[nx][ny] == 1) {
                    if (breaked) {
                        continue;
                    }
                    nb = true;
                }
                if (visited[nx][ny][nb]) {
                    continue;
                }
                visited[nx][ny][nb] = true;
                q.push({{nx, ny}, nb});
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

    cin >> N >> M >> Hx >> Hy >> Ex >> Ey;

    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    cout << bfs() << "\n";

    return 0;
}