#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector< pair<int, int> > s[101][101];
int n, m, visited[101][101], numLight = 1;
bool light[101][101];

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void turnOnLights(int x, int y) {
    for(int i = 0; i < s[x][y].size(); i++) {
        int lx = s[x][y][i].first;
        int ly = s[x][y][i].second;
        if(!light[lx][ly]) {
            light[lx][ly] = true;
            numLight++;
        }
    }
}

void bfs() {
    queue< pair<int, int> > q;
    q.push(make_pair(1, 1));
    while(!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI <= 0 || nI > n || nJ <= 0 || nJ > n)
                continue;
            if(light[nI][nJ] == false || visited[nI][nJ] >= numLight)
                continue;
            turnOnLights(nI, nJ);
            visited[nI][nJ] = numLight;
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
    
    light[1][1] = true;
    turnOnLights(1, 1);
    visited[1][1] = numLight;

    bfs();

    cout << numLight << '\n';

    return 0;
}