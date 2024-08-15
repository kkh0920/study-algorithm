#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c, n;
char map[101][102];
bool visited[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void initVisited() {
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            visited[i][j] = false;
        }
    }
}

bool canDrop(vector< pair<int, int> > cluster, int dropHeight) {
    for(auto c : cluster) {
        int x = c.first - dropHeight, y = c.second;
        if(x < 1 || map[x][y] == 'x') {
            return false;
        }
    }
    return true;
}

void drop(vector< pair<int, int> > cluster) {
    for(auto c : cluster) {
        map[c.first][c.second] = '.';
    }
    int dropHeight = 0;
    while(1) {
        if(!canDrop(cluster, dropHeight + 1)) {
            for(auto c : cluster) {
                map[c.first - dropHeight][c.second] = 'x';
            }
            return;
        }
        dropHeight++;
    }
}

bool isdropped(int si, int sj) {
    vector< pair<int, int> > cluster;
    cluster.push_back(make_pair(si, sj));

    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));
    
    visited[si][sj] = true;

    bool canDrop = true;
    while(!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 1) {
                canDrop = false;
                continue;
            }
            if(nI > r || nJ < 1 || nJ > c) continue;
            if(visited[nI][nJ] || map[nI][nJ] == '.') continue;
            visited[nI][nJ] = true;
            cluster.push_back(make_pair(nI, nJ));
            q.push(make_pair(nI, nJ));
        }
    }
    if(!canDrop) return false;
    
    drop(cluster);

    return true;
}

void throwSpear(int height, int time) {
    int sx = height, sy = 0;
    if(time % 2 == 0) { // left
        for(int i = 1; i <= c; i++) {
            if(map[height][i] == 'x') {
                map[height][i] = '.';
                sy = i;
                break;
            }
        }
    } else { // right
        for(int i = c; i >= 1; i--) {
            if(map[height][i] == 'x') {
                map[height][i] = '.';
                sy = i;
                break;
            }
        }
    }
    if(sy == 0) return;

    for(int i = 0; i < 4; i++) {
        int x = sx + dx[i], y = sy + dy[i];
        if(x < 1 || x > r || y < 1 || y > c) continue;
        if(visited[x][y] || map[x][y] == '.') continue;
        if(isdropped(x, y)) 
            return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> r >> c;

    for(int i = r; i >= 1; i--) {
        for(int j = 1; j <= c; j++) {
            cin >> map[i][j];
        }
    }

    cin >> n;

    int h;
    for(int i = 0; i < n; i++) {
        cin >> h;
        initVisited();
        throwSpear(h, i);
    }

    for(int i = r; i >= 1; i--) {
        for(int j = 1; j <= c; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }

    return 0;
}