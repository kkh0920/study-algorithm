#include <iostream>
#include <queue>
using namespace std;

int r, c;
int visited[3][101][101], arrival[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

char map[101][102];

queue< pair<int, int> > q[3];

void move(int index, int time) {
    int size = q[index].size();
    while(size--) {
        int curX = q[index].front().first;
        int curY = q[index].front().second;
        q[index].pop();
        for(int i = 0; i < 4; i++) {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            if(nX < 1 || nX > r || nY < 1 || nY > c) continue;
            if(visited[index][nX][nY] || map[nX][nY] == '1') continue;
            visited[index][nX][nY] = time;
            q[index].push(make_pair(nX, nY));
        }    
    }
}

pair<int, int> bfs() {
    int time = 1;
    bool meet = false;
    while(!q[0].empty() || !q[1].empty() || !q[2].empty()) {
        move(0, time + 1);
        move(1, time + 1);
        move(2, time + 1);
        time++;
    }

    int minTime = 999999;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= r; j++) {
            if(visited[0][i][j] && visited[1][i][j] && visited[2][i][j]) {
                arrival[i][j] = max(visited[0][i][j], max(visited[1][i][j], visited[2][i][j]));
                minTime = min(minTime, arrival[i][j]);
            }
        }
    }

    int count = 0;
    if(minTime != 99999) {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= r; j++) {
                if(minTime == arrival[i][j]) count++;
            }
        }
    }

    return make_pair(minTime - 1, count);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> map[i][j];
        }
    }

    int x, y;
    for(int i = 0; i < 3; i++) {
        cin >> x >> y;
        q[i].push(make_pair(x, y));
        visited[i][x][y] = 1;
    }

    pair<int, int> result = bfs();

    if(result.second == 0) {
        cout << -1 << '\n';
    } else {
        cout << result.first << '\n' << result.second << '\n';
    }

    return 0;
}