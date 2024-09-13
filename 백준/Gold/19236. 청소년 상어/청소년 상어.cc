#include <iostream>
using namespace std;

struct Fish {
    int index, dir;
};

Fish map[4][4];
pair<int, int> point[17];
bool removed[17];

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int sum = 0, result = 0;

void copy(Fish map[4][4], Fish tempMap[4][4], 
            pair<int, int> point[17], pair<int, int> tempPoint[17]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            tempMap[i][j] = map[i][j];
            tempPoint[4 * i + j + 1] = point[4 * i + j + 1];
        }
    }
}

void moveFish(int sharkX, int sharkY) {
    for(int i = 1; i <= 16; i++) {
        int x = point[i].first;
        int y = point[i].second;
        
        if(removed[i]) continue;
        
        for(int j = 0; j < 8; j++) {
            int nx = x + dx[map[x][y].dir];
            int ny = y + dy[map[x][y].dir];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || 
                        (nx == sharkX && ny == sharkY)) {
                map[x][y].dir = (map[x][y].dir + 1) % 8;
                continue;
            }

            if(map[nx][ny].index == 0) {
                point[i] = { nx, ny };
            } else {
                swap(point[i], point[map[nx][ny].index]);
            }
            swap(map[x][y], map[nx][ny]);
            
            break;
        }
    }
}

void moveShark(int x, int y, int dir) {
    Fish tempMap[4][4];
    pair<int, int> tempPoint[17];
    copy(map, tempMap, point, tempPoint);

    moveFish(x, y);

    bool isMoved = false;
    int nx = x, ny = y;
    while(nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
        if(map[nx][ny].index == 0) {
            nx += dx[dir];
            ny += dy[dir];
            continue;
        }
        isMoved = true;
        int idx = map[nx][ny].index;

        removed[idx] = true;
        sum += idx;
        map[nx][ny].index = 0;

        moveShark(nx, ny, map[nx][ny].dir);
        
        removed[idx] = false;
        sum -= idx;
        map[nx][ny].index = idx;
        

        nx += dx[dir];
        ny += dy[dir];
    }
    
    copy(tempMap, map, tempPoint, point);

    if(!isMoved) {
        result = max(result, sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int index, dir;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> index >> dir;
            map[i][j] = { index, dir - 1 };
            point[index] = { i, j };
        }
    }

    removed[map[0][0].index] = true;
    sum = map[0][0].index;
    map[0][0].index = 0;
    moveShark(0, 0, map[0][0].dir);

    cout << result << '\n';
}