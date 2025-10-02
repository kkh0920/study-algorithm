#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M, map[100][70];
bool visited[100][70];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    int base = map[startX][startY];
    bool isPeak = true;

    q.push({startX, startY});
    visited[startX][startY] = true;

    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) {
                continue;
            }
            if (map[nextX][nextY] > base) {
                isPeak = false;
                continue;
            }
            if (map[nextX][nextY] < base || visited[nextX][nextY]) {
                continue;
            }
            visited[nextX][nextY] = true;
            q.push({nextX, nextY});
        }
    }
    
    return isPeak;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                result += bfs(i, j) ? 1 : 0;
            }
        }
    }

    cout << result << '\n';

    return 0;
}