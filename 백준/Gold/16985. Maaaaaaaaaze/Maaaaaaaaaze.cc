#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define INF 987654321

bool map[5][5][5], visited[5][5][5];

int points[4][6] = {
    // {{start}, {end}}
    {0, 0, 0,  4, 4, 4}, {0, 0, 4,  4, 4, 0},
    {0, 4, 0,  4, 0, 4}, {0, 4, 4,  4, 0, 0}
};

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int result = INF;

void bfs(
    int startX, int startY, int startZ, 
    int endX, int endY, int endZ
) {
    queue< pair<int, pair<int, int> > > q;
    q.push({startX, {startY, startZ}});

    memset(visited, false, sizeof(visited));
    visited[startX][startY][startZ] = true;

    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int curX = q.front().first;
            int curY = q.front().second.first;
            int curZ = q.front().second.second;
            q.pop();
            
            if (time >= result) {
                return;
            }

            if (curX == endX && curY == endY && curZ == endZ) {
                result = time;
                return;
            }

            for (int i = 0; i < 6; i++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                int nextZ = curZ + dz[i];

                if (
                    nextX < 0 || nextX >= 5 || 
                    nextY < 0 || nextY >= 5 || 
                    nextZ < 0 || nextZ >= 5
                ) {
                    continue;
                }
                if (visited[nextX][nextY][nextZ] || map[nextX][nextY][nextZ] == 0) {
                    continue;
                }

                visited[nextX][nextY][nextZ] = true;
                q.push({nextX, {nextY, nextZ}});
            }
        }
        time++;
    }
}

void rotate(bool flat[5][5]) {
    bool temp[5][5];
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            temp[y][4 - x] = flat[x][y];
        }
    }
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            flat[x][y] = temp[x][y];
        }
    }
}

void rotate_map(int index) {
    if (index > 4) {
        for (int i = 0; i < 4; i++) {
            if (
                map[points[i][0]][points[i][1]][points[i][2]] == 1 && 
                map[points[i][3]][points[i][4]][points[i][5]] == 1 && 
                result > 12
            ) {
                bfs(points[i][0], points[i][1], points[i][2], 
                    points[i][3], points[i][4], points[i][5]);
            }
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        rotate_map(index + 1);
        rotate(map[index]);
    }
}

void permute_map(int index) {
    if (index > 4) {
        rotate_map(0);
        return;
    }
    for (int i = index; i < 5; i++) {
        swap(map[index], map[i]);
        permute_map(index + 1);
        swap(map[index], map[i]);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> map[i][j][k];
            }
        }
    }

    permute_map(0);

    cout << (result == INF ? -1 : result) << '\n';

    return 0;
}