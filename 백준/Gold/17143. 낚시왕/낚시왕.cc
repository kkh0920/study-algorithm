#include <iostream>
#include <queue>
using namespace std;

struct Shark {
    int s;
    int d;
    int z;
};

int R, C, M;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

queue< pair<int, int> > point;

Shark grid[101][101], temp[101][101];

void moveFrom(int x, int y) {
    if(grid[x][y].z == -1) 
        return;

    Shark shark = grid[x][y];
    int nX = x, nY = y;
    int s = shark.s, d = shark.d;
    while(s > 0) {
        switch(d) {
            case 0:
                if(s > nX - 1) {
                    s -= nX - 1; nX = 1; 
                    d = 1;
                } else {
                    nX -= s; s = 0;
                }
                break;
            case 1:
                if(s > R - nX) {
                    s -= R - nX; nX = R; 
                    d = 0;
                } else {
                    nX += s; s = 0;
                }
                break;
            case 2:
                if(s > C - nY) {
                    s -= C - nY; nY = C; 
                    d = 3;
                } else {
                    nY += s; s = 0;
                }
                break;
            case 3:
                if(s > nY - 1) {
                    s -= nY - 1; nY = 1; 
                    d = 2;
                } else {
                    nY -= s; s = 0;
                }
                break;
        }
    }
    shark.d = d;
    
    if(shark.z > temp[nX][nY].z) {
        temp[nX][nY] = shark;
    }
}

void moveAll() {
    while(!point.empty()) {    
        moveFrom(point.front().first, point.front().second);
        point.pop();
    }
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            grid[i][j] = temp[i][j];
            temp[i][j] = { -1, -1, -1 };
            if(grid[i][j].z != -1) {
                point.push(make_pair(i, j));
            }
        }
    }
}

int simulation() {
    int result = 0;
    for(int i = 1; i <= C; i++) {
        for(int j = 1; j <= R; j++) {
            if(grid[j][i].z != -1) {
                result += grid[j][i].z;
                grid[j][i] = { -1, -1, -1 };
                break;
            }
        }
        moveAll();
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> M;

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            temp[i][j] = { -1, -1, -1 };
            grid[i][j] = { -1, -1, -1 };
        }
    }

    int r, c, s, d, z;
    for(int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        point.push(make_pair(r, c));
        grid[r][c] = { s, d - 1, z };
    }

    cout << simulation() << '\n';

    return 0;
}