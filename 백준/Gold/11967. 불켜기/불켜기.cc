#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, numLight = 1;
vector< pair<int, int> > s[101][101];
bool light[101][101], visited[101][101];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void bfs() {
    queue< pair<int, int> > q;
    q.push(make_pair(1, 1));
    light[1][1] = true;
    visited[1][1] = true;
    while(!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();
        for(auto l : s[curI][curJ]) {
            if(light[l.first][l.second])
                continue;
            numLight++;
            light[l.first][l.second] = true;
            for(int i = 0; i < 4; i++) {
                if(visited[l.first + dx[i]][l.second + dy[i]]) {
                    visited[l.first][l.second] = true;
                    q.push(make_pair(l.first, l.second));
                    break;
                }
            }
        }
        for(int i = 0; i < 4; i++) {
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI <= 0 || nI > n || nJ <= 0 || nJ > n)
                continue;
            if(visited[nI][nJ] || !light[nI][nJ])
                continue;
            visited[nI][nJ] = true;  
            q.push(make_pair(nI, nJ));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int x1, y1, x2, y2;
    for(int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        s[x1][y1].push_back(make_pair(x2, y2));
    }
    
    bfs();

    cout << numLight << '\n';

    return 0;
}