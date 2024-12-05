#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool visited[301][301];

char map[301][301];

queue< pair<int, int> > q, temp;

bool bfs() {
    q = temp;
    while(!temp.empty()) {
        temp.pop();
    }
    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        if(map[curX][curY] == '1') {
            map[curX][curY] = '0';
            temp.push({curX, curY});
            continue;
        }
        if(map[curX][curY] == '#') {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            if(nX < 0 || nX >= N || nY < 0 || nY >= M || visited[nX][nY]) {
                continue;
            }
            visited[nX][nY] = true;
            q.push({nX, nY});
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    visited[x1 - 1][y1 - 1] = true;
    temp.push({x1 - 1, y1 - 1});

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int result = 1;
    while(!bfs()) {
        result++;
    }
    
    cout << result << '\n';

    return 0;
}