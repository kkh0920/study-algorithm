#include <iostream>
#include <queue>
using namespace std;

struct State {
    int health, barrior;
    int x, y;
};

int n, h, d;
char map[501][501];
int visited[501][501];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<State> q;

int bfs() {
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int curHealth = q.front().health;
            int curBarrior = q.front().barrior;
            int curX = q.front().x;
            int curY = q.front().y;
            q.pop();

            if(map[curX][curY] == 'E')
                return time;

            for(int i = 0; i < 4; i++) {
                int nextHealth = curHealth;
                int nextBarrior = curBarrior;
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];

                if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
                    continue;

                if(map[nextX][nextY] == 'U')
                    nextBarrior = d - 1;
                else if(map[nextX][nextY] == '.')
                    curBarrior == 0 ? nextHealth-- : nextBarrior--;

                if(nextHealth <= 0)
                    continue;

                if(visited[nextX][nextY] < nextHealth + nextBarrior) {
                    visited[nextX][nextY] = nextHealth + nextBarrior;
                    q.push({ nextHealth, nextBarrior, nextX, nextY });
                }
            }
        }
        time++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h >> d;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'S') {
                q.push({ h, 0, i ,j });
                visited[i][j] = h;
            }
        }
    }

    cout << bfs() << '\n';

    return 0;
}