#include <iostream>
#include <queue>
using namespace std;

#define INF 999999

int N, M;
char map[500][501];

int visited[500][500];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = -1;
        }
    }
}

void rotateDir(int &dir, char c) {
    if(c == '/') {
        if(dir == 0) dir = 1;
        else if(dir == 1) dir = 0;
        else if(dir == 2) dir = 3;
        else if(dir == 3) dir = 2;
    } else if(c == '\\') {
        if(dir == 0) dir = 3;
        else if(dir == 1) dir = 2;
        else if(dir == 2) dir = 1;
        else if(dir == 3) dir = 0;
    }
}

int signal(int x, int y, int dir) {
    int time = 0;
    int curX = x, curY = y, curDir = dir;
    while(1) {
        curX += dx[curDir];
        curY += dy[curDir];
        time++;
        if(curX < 0 || curX >= N || curY < 0 || curY >= M || map[curX][curY] == 'C') {
            break;
        }
        if(visited[curX][curY] == curDir) {
            time = INF;
            break;
        }
        visited[curX][curY] = curDir;
        if(map[curX][curY] == '/' || map[curX][curY] == '\\') {
            rotateDir(curDir, map[curX][curY]);
        }
    }
    return time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    int result = 0, dir;
    for(int i = 0; i < 4; i++) {
        init();
        int time = signal(x - 1, y - 1, i);
        if(result < time) {
            dir = i;
            result = time;
        }
        if(result == INF) break;
    }

    char d[5] = { 'U', 'R', 'D', 'L', '\0' };
    cout << d[dir] << '\n';
    if(result == INF) {
        cout << "Voyager" << '\n';
    } else {
        cout << result << '\n';
    }

    return 0;
}