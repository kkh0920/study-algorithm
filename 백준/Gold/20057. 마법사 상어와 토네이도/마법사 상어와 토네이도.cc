#include <iostream>
using namespace std;

int N, arr[500][500], result = 0;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int ddx[9] = { -2, -1, -1, -1, 0, 1, 1, 1, 2 };
int ddy[9] = { 0, -1, 0, 1, -2, -1, 0, 1, 0 };

double rate[9] = { 0.02, 0.1, 0.07, 0.01, 0.05, 0.1, 0.07, 0.01, 0.02 };

void rotateDir(int &dir) {
    dir = (dir + 1) % 4;
}

pair<int, int> rotatePoint(int index, int dir) {
    int x = ddx[index];
    int y = ddy[index];
    if(dir == 1) return { -y, x };
    if(dir == 2) return { -x, -y };
    if(dir == 3) return { y, -x };
    return { x, y };
}

void spread(int x, int y, int dir) {
    int spreadSand = 0;
    for(int i = 0; i < 9; i++) {
        pair<int, int> p = rotatePoint(i, dir);
        int nx = x + p.first;
        int ny = y + p.second;
        int spread = arr[x][y] * rate[i];
        spreadSand += spread;
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
            result += spread;
            continue;
        }
        arr[nx][ny] += spread;
    }
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
        result += arr[x][y] - spreadSand;
    } else {
        arr[nx][ny] += arr[x][y] - spreadSand;
    }
    arr[x][y] = 0;
}

void move(int &dir, int moveDist, int &x, int &y) {
    while(moveDist--) {
        x += dx[dir];
        y += dy[dir];
        spread(x, y, dir);
        if(x == 0 && y == 0) return;
    }
    rotateDir(dir);
}

void simulation(int startX, int startY) {
    int curDir = 0, moveDist = 1, moveCnt = 0;
    int curX = startX, curY = startY;
    while(1) {
        if(curX == 0 && curY == 0) break;
        move(curDir, moveDist, curX, curY);
        if(++moveCnt % 2 == 0) moveDist++;
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    simulation(N / 2, N / 2);

    return 0;
}