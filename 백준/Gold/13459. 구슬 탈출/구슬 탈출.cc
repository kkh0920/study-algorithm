#include <iostream>
#include <queue>
using namespace std;

int N, M, limit = 10;

int redStartX, redStartY, blueStartX, blueStartY;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

char map[10][10];
bool visited[10][10][10][10];

bool tryMove(int *redX, int *redY, int *blueX, int *blueY, int dir) {
    bool redMoved = true, blueMoved = true;
    /*
        두 구슬 모두 이동할 수 없을 때까지 서로 번갈아가며 한 칸씩 이동시킨다.
    */
    while (redMoved || blueMoved) {
        redMoved = true;
        blueMoved = true;
        
        /*
            1. 다음 이동 위치가 벽이거나,
            2. 다음 이동 위치가 다른 구슬이 있는 위치이거나 (다른 구슬이 구멍에 빠진 경우는 제외),
            3. 현재 위치가 구멍인 경우,
            해당 구슬 이동을 일시적으로 멈춘다.
        */
        
        // 빨간 구슬 한칸 이동
        if (
            // 1.
            map[*redX + dx[dir]][*redY + dy[dir]] == '#' ||
            // 2.
            ((*redX + dx[dir] == *blueX && *redY + dy[dir] == *blueY) && (map[*blueX][*blueY] != 'O')) ||
            // 3.
            map[*redX][*redY] == 'O'
        ) {
            redMoved = false;
        } else {
            *redX += dx[dir];
            *redY += dy[dir];
        }
        
        // 파란 구슬 한칸 이동
        if (
            // 1.
            map[*blueX + dx[dir]][*blueY + dy[dir]] == '#' ||
            // 2.
            ((*blueX + dx[dir] == *redX && *blueY + dy[dir] == *redY) && (map[*redX][*redY] != 'O')) || 
            // 3.
            map[*blueX][*blueY] == 'O'
        ) {
            blueMoved = false;
        } else {
            *blueX += dx[dir];
            *blueY += dy[dir];
        }
    }

    /*
        이미 방문한 위치이거나 파란 구슬이 구멍에 빠진 경우, 이동 불가능한 위치로 간주한다.
    */
    if (visited[*redX][*redY][*blueX][*blueY] || map[*blueX][*blueY] == 'O') {
        return false;
    }
    
    return true;
}

bool bfs() {
    queue< pair<int, int> > red;
    queue< pair<int, int> > blue;

    red.push({redStartX, redStartY});
    blue.push({blueStartX, blueStartY});

    visited[redStartX][redStartY][blueStartX][blueStartY] = true;

    int time = 0;
    while (time < limit && !red.empty() && !blue.empty()) {
        int count = red.size(); // 시간 체크를 위한 변수
        
        while (count--) {
            int redX = red.front().first, redY = red.front().second;
            int blueX = blue.front().first, blueY = blue.front().second;
            red.pop();
            blue.pop();
            
            for (int i = 0; i < 4; i++) {
                int redNextX = redX, redNextY = redY;
                int blueNextX = blueX, blueNextY = blueY;
                
                if (tryMove(&redNextX, &redNextY, &blueNextX, &blueNextY, i)) {
                    if (map[redNextX][redNextY] == 'O') {
                        return true;
                    }

                    red.push({redNextX, redNextY});
                    blue.push({blueNextX, blueNextY});

                    visited[redNextX][redNextY][blueNextX][blueNextY] = true;
                }
            }
        }
        
        time++;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                redStartX = i;
                redStartY = j;
            } else if (map[i][j] == 'B') {
                blueStartX = i;
                blueStartY = j;
            }
        }
    }

    cout << (bfs() ? 1 : 0) << "\n";

    return 0;
}