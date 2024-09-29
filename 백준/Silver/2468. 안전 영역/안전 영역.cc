#include <iostream>
#include <queue>
using namespace std;

int N, arr[100][100];
bool visited[100][100];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

void bfs(int height, int x, int y) {
    queue< pair<int, int> > q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            if(nX < 0 || nX >= N || nY < 0 || nY >= N) continue;
            if(arr[nX][nY] <= height || visited[nX][nY]) continue;
            visited[nX][nY] = true;
            q.push({nX, nY});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int maxHeight = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            maxHeight = max(maxHeight, arr[i][j]);
        }
    }

    int result = 0;
    for(int i = 0; i < maxHeight; i++) {
        init();
        int num = 0;
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(arr[j][k] > i && !visited[j][k]) {
                    bfs(i, j, k);
                    num++;
                }
            }
        }
        result = max(result, num);
    }

    cout << result << '\n';

    return 0;
}