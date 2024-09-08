#include <iostream>
#include <queue>
using namespace std;

int N, M, map[1000][1000], vtime[1000][1000], result[3];
queue< pair<int, int> > virus;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs() {
    while(!virus.empty()) {
        int x = virus.front().first;
        int y = virus.front().second;
        virus.pop();

        if(map[x][y] == 3) {
            continue;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == -1) {
                continue;
            }
            if(map[nx][ny] == 0) {
                map[nx][ny] = map[x][y];
                vtime[nx][ny] = vtime[x][y] + 1;
                virus.push({nx, ny});
            } else if(map[nx][ny] != map[x][y] && vtime[nx][ny] == vtime[x][y] + 1) {
                map[nx][ny] = 3;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            vtime[i][j] = -1;
            if(map[i][j] == 1 || map[i][j] == 2) {
                virus.push({i, j});
                vtime[i][j] = 0;
            }
        }
    }

    bfs();
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] > 0) {
                result[map[i][j] - 1]++;
            }
        }
    }

    cout << result[0] << ' ' << result[1] << ' ' << result[2] << '\n';

    return 0;
}