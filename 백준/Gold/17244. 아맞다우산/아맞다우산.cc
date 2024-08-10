#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue< pair<int, pair<int, int> > > q;
bool visited[32][50][50];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m, weight[50][50], fullWeight = 0;
char map[50][51];

int bfs() {
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int curWeight = q.front().first;
            int curI = q.front().second.first;
            int curJ = q.front().second.second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nWeight = curWeight;
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                if(nI < 0 || nI >= m || nJ < 0 || nJ >= n || map[nI][nJ] == '#')
                    continue;
                if(map[nI][nJ] == 'E' && curWeight == fullWeight)
                    return time + 1;
                if(map[nI][nJ] == 'X' && !(curWeight & weight[nI][nJ]))
                    nWeight += weight[nI][nJ];
                if(!visited[nWeight][nI][nJ]) {
                    visited[nWeight][nI][nJ] = true;
                    q.push(make_pair(nWeight, make_pair(nI, nJ)));
                }
            }
        }
        time++;
    }
    return -1; // 모든 물건을 챙길 수 없는 경우는 주어지지 않는다.
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int w = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'S') {
                q.push(make_pair(0, make_pair(i, j)));
                visited[0][i][j] = true;
            } else if(map[i][j] == 'X') {
                weight[i][j] = w; 
                fullWeight += w;
                w *= 2;
            }
        }
    }

    cout << bfs() << '\n';

    return 0;
}