#include <iostream>
#include <queue>
using namespace std;

queue< pair<int, int> > q, v;
int map[200][200], n, k, s, x, y;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
bool visited[200][200];

void bfs() {
    while(!q.empty() && s > 0) {
        int cnt = q.size();
        while(cnt--) {
            int curI = q.front().first;
            int curJ = q.front().second;
            q.pop();

            int curVirus = map[curI][curJ];

            for(int i = 0; i < 4; i++) {
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                if(nI < 0 || nI >= n || nJ < 0 || nJ >= n)
                    continue;
                if(visited[nI][nJ])
                    continue;
                if(map[nI][nJ] != 0 && map[nI][nJ] <= curVirus)
                    continue;
                map[nI][nJ] = curVirus;
                v.push(make_pair(nI, nJ));
                q.push(make_pair(nI, nJ));
            }
        }

        while(!v.empty()) {
            int i = v.front().first;
            int j = v.front().second;
            visited[i][j] = true;
            v.pop();
        }

        s--;
    }
}

int main() {

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] > 0) {
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }
    cin >> s >> x >> y;

    bfs();

    cout << map[x - 1][y - 1] << '\n';
    
    return 0;
}