#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< pair<int, int> > coin;
queue< pair<int, int> > q;
bool visited[20][20][20][20];
char map[20][20];
int n, m, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

bool isDrop(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return true;
    }
    return false;
}

int bfs() {
    int cnt = 0;
    while(!q.empty()) {
        int size = q.size() / 2;
        while(size--) {
            int x1 = q.front().first;
            int y1 = q.front().second;
            q.pop();
            int x2 = q.front().first;
            int y2 = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
                int nx2 = x2 + dx[i], ny2 = y2 + dy[i];
                if(isDrop(nx1, ny1) && isDrop(nx2, ny2)) {
                    continue;
                }
                if(isDrop(nx1, ny1) ^ isDrop(nx2, ny2)) {
                    return cnt + 1;
                }

                if(map[nx1][ny1] == '#') {
                    nx1 = x1; ny1 = y1;
                }
                if(map[nx2][ny2] == '#') {
                    nx2 = x2; ny2 = y2;
                }

                if(visited[nx1][ny1][nx2][ny2] || visited[nx2][ny2][nx1][ny1]) {
                    continue;
                }

                visited[nx1][ny1][nx2][ny2] = true;
                visited[nx2][ny2][nx1][ny1] = true;

                q.push(make_pair(nx1, ny1));
                q.push(make_pair(nx2, ny2));
            }
        }
        if(++cnt >= 10) return -1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'o') {
                coin.push_back(make_pair(i, j));
            }
        }
    }
    
    int x1 = coin[0].first, y1 = coin[0].second;
    int x2 = coin[1].first, y2 = coin[1].second;

    visited[x1][y1][x2][y2] = true;
    visited[x2][y2][x1][y1] = true;

    q.push(make_pair(x1, y1));
    q.push(make_pair(x2, y2));

    cout << bfs() << '\n';

    return 0;
}