#include <iostream>
#include <queue>
using namespace std;

queue< pair<int, int> > q;
bool visited[10][9];

int r1, c1, r2, c2;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int ddx[4][2] = {
    { -1, -1 }, { -1, 1 }, { -1, 1 }, { 1, 1 }
};
int ddy[4][2] = {
    { -1, 1 }, { -1, -1 }, { 1, 1 }, { -1, 1 }
};

bool isInside(int x, int y) {
    if(x < 0 || x >= 10 || y < 0 || y >= 9) {
        return false;
    }
    return true;
}
 
void move(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!isInside(x, y) || (x == r2 && x == c2)) {
            continue;
        }
        for(int j = 0; j < 2; j++) {
            int nnx = nx + ddx[i][j];
            int nny = ny + ddy[i][j];

            if(!isInside(nnx, nny) || (nnx == r2 && nny == c2)) continue;
            if(!isInside(nnx + ddx[i][j], nny + ddy[i][j])) continue;
            if(visited[nnx + ddx[i][j]][nny + ddy[i][j]]) continue;
            
            q.push({nnx + ddx[i][j], nny + ddy[i][j]});
            visited[nnx + ddx[i][j]][nny + ddy[i][j]] = true;
        }
    }
}

int solve() {
    q.push({r1, c1});
    visited[r1][c1] = true;
    int moveCount = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            if(curX == r2 && curY == c2) {
                return moveCount;
            }
            move(curX, curY);
        }
        moveCount++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r1 >> c1 >> r2 >> c2;

    cout << solve() << '\n';

    return 0;
}