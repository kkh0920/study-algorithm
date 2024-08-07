#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, map[20][20], score = 0;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
bool visited[20][20];

// dice number
int l = 4, t = 2, r = 3, b = 5;
int f = 6, c = 1;

// dice vector
int x = 0, y = 0, dir = 0;

void initVisited() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = false; 
        }
    }
}

void rollDice() {
    if(x + dx[dir] < 0) {
        dir = 1;
    } else if(x + dx[dir] >= n) {
        dir = 3;
    } else if(y + dy[dir] < 0) {
        dir = 0;
    } else if(y + dy[dir] >= m) {
        dir = 2;
    }
    x += dx[dir]; y += dy[dir];

    int tmp = f;
    switch(dir) {
        case 0:
            f = r; r = c; c = l; l = tmp;
            break;
        case 1:
            f = b; b = c; c = t; t = tmp;
            break;
        case 2:
            f = l; l = c; c = r; r = tmp;
            break;
        case 3:
            f = t; t = c; c = b; b = tmp;
            break;
    }
}

int getScore() {
    queue< pair<int, int> > q;
    q.push(make_pair(x, y));

    initVisited();
    visited[x][y] = true;
    
    int num = map[x][y];
    int count = 1;
    while(!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= n || nJ < 0 || nJ >= m)
                continue;
            if(visited[nI][nJ] || map[nI][nJ] != num)
                continue;
            count++;
            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }

    return num * count;
}

void rotateDice() {
    if(f > map[x][y] && ++dir > 3) {
        dir = 0;
    } else if(f < map[x][y] && --dir < 0) {
        dir = 3;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while(k--) {
        rollDice();
        score += getScore(); 
        rotateDice();
    }

    cout << score << '\n';

    return 0;
}