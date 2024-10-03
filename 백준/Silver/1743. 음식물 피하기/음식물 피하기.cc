#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
bool exist[101][101], visited[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int getSize(int x, int y) {
    queue< pair<int, int> > q;
    q.push({x, y});
    visited[x][y] = true;
    int size = 1;
    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            if(nX < 1 || nX > N || nY < 1 || nY > M) continue;
            if(!exist[nX][nY] || visited[nX][nY]) continue;
            visited[nX][nY] = true;
            q.push({nX, nY});
            size++;
        }
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    int r, c;
    for(int i = 0; i < K; i++) {
        cin >> r >> c;
        exist[r][c] = true;
    }

    int result = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(!visited[i][j] && exist[i][j]) {
                result = max(result, getSize(i, j));
            }
        }
    }

    cout << result << '\n';

    return 0;
}