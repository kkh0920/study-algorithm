#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector< pair<int, int> > v;

int W, H;
bool home[100][100], visited[100][100];

int dx1[6] = { 0, 1, -1, 1, 0, 1 };
int dx2[6] = { -1, 0, -1, 1, -1, 0 };

int dy[6] = { -1, -1, 0, 0, 1, 1 };

int cal(int x, int y) {
    int res = 0;
    for(int i = 0; i < 6; i++) {
        int nX, nY = y + dy[i];
        if(y % 2 == 0) {
            nX = x + dx1[i];
        } else {
            nX = x + dx2[i];
        }
        if(nX < 0 || nX >= W || nY < 0 || nY >= H || !home[nY][nX]) {
            res++;
        }
    }
    return res;
}

void bfs(int x, int y) {
    queue< pair<int, int> > q;
    q.push({x, y});
    visited[y][x] = true;
    v.clear();
    v.push_back({x, y});
    bool block = true;
    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i = 0; i < 6; i++ ){
            int nX, nY = curY + dy[i];
            if(curY % 2 == 0) {
                nX = curX + dx1[i];
            } else {
                nX = curX + dx2[i];
            }

            if(nX < 0 || nX >= W || nY < 0 || nY >= H) {
                block = false;
                continue;
            }
            if(visited[nY][nX] || home[nY][nX]) continue;
            
            visited[nY][nX] = true;
            v.push_back({nX, nY});
            q.push({nX, nY});
        }
    }

    if(!block) return;

    for(auto i : v) {
        home[i.second][i.first] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> W >> H;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> home[i][j];
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(!visited[i][j] && !home[i][j]) {
                bfs(j, i);
            }
        }
    }

    int result = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(home[i][j]) {
                result += cal(j, i);
            }
        }
    }

    cout << result << '\n';

    return 0;
}