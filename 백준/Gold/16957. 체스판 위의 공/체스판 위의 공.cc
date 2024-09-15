#include <iostream>
using namespace std;

int r, c, map[500][500], result[500][500];
pair<int, int> dest[500][500];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

pair<int, int> moveFrom(int x, int y) {
    if(dest[x][y].first != -1) {
        result[dest[x][y].first][dest[x][y].second]++;
        return dest[x][y];
    }

    int min = 300001, nx, ny;
    for(int i = 0; i < 8; i++) {
        int bx = x + dx[i], by = y + dy[i];
        if(bx < 0 || bx >= r || by < 0 || by >= c) {
            continue;
        }
        if(min > map[bx][by]) {
            min = map[bx][by];
            nx = bx;
            ny = by;
        }
    }

    if(min < map[x][y]) {
        return dest[x][y] = moveFrom(nx, ny);
    }

    result[x][y]++;
    return dest[x][y] = { x, y };    
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> map[i][j];
            dest[i][j] = { -1, -1 };
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            moveFrom(i, j);
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}