#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[100][101];
bool visited[100][100];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue< pair<int, int> > wolf;

void bfs() {
    while(!wolf.empty()) {
        int x = wolf.front().first;
        int y = wolf.front().second;
        wolf.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(map[nx][ny] == '#' || visited[nx][ny]) 
                continue;

            while(map[nx][ny] == '+') {
                nx += dx[i]; ny += dy[i];
            }
            if(map[nx][ny] == '#') {
                nx -= dx[i]; ny -= dy[i];
            }

            if(!visited[nx][ny]) {
                visited[nx][ny] = true;
                wolf.push({nx, ny});
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
            if(map[i][j] == 'W') {
                wolf.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    bfs();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == '.' && !visited[i][j]) {
                cout << 'P';
            } else {
                cout << map[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}