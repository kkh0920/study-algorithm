#include <iostream>
#include <queue>
using namespace std;

struct State {
    bool canBreak;
    int breakCnt;
    int curI, curJ;
};

int n, m, k, visited[2][1000][1000];
char map[1000][1001];

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

int bfs() {
    if(n == 1 && m == 1) return 1;
    queue<State> q;
    q.push({true, 0, 0, 0});
    visited[1][0][0] = 0;
    int dist = 1;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            bool canBreak = q.front().canBreak;
            int breakCnt = q.front().breakCnt;
            int curI = q.front().curI;
            int curJ = q.front().curJ;
            q.pop();

            for(int i = 0; i < 5; i++) {
                int nBreakCnt = breakCnt;
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                
                if(nI < 0 || nI >= n || nJ < 0 || nJ >= m)
                    continue;
                if(nI == n - 1 && nJ == m - 1)
                    return dist + 1;
      
                if(i != 0 && map[nI][nJ] == '1') {
                    if(canBreak && breakCnt < k) nBreakCnt++;
                    else continue;
                }
                
                if(nBreakCnt < visited[!canBreak][nI][nJ]) {
                    visited[!canBreak][nI][nJ] = nBreakCnt;
                    q.push({!canBreak, nBreakCnt, nI, nJ});
                }
            }
        }
        dist++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            visited[0][i][j] = 99999;
            visited[1][i][j] = 99999;
        }
    }

    cout << bfs() << '\n';

    return 0;
}