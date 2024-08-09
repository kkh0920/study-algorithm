#include <iostream>
#include <queue>
using namespace std;

queue< pair<int, pair<int, int> > > q;
bool visited[31][31][31];

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int l, r, c;
char map[31][31][31];

void init() {
    while(!q.empty()) {
        q.pop();
    }
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < r; j++) {
            for(int k = 0; k < c; k++) {
                visited[i][j][k] = false;
            }
        }
    }
}

int bfs() {
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int curI = q.front().first;
            int curJ = q.front().second.first;
            int curK = q.front().second.second;
            q.pop();
            for(int i = 0; i < 6; i++) {
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                int nK = curK + dz[i];
                if(nI < 0 || nI >= l || nJ < 0 || nJ >= r || nK < 0 || nK >= c)
                    continue;
                if(visited[nI][nJ][nK] || map[nI][nJ][nK] == '#')
                    continue;
                if(map[nI][nJ][nK] == 'E')
                    return time + 1;
                visited[nI][nJ][nK] = true;
                q.push(make_pair(nI, make_pair(nJ, nK)));
            }
        }
        time++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(1) {
        cin >> l >> r >> c; 
        if(l == 0) break;
        init();
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                for(int k = 0; k < c; k++) {
                    cin >> map[i][j][k];
                    if(map[i][j][k] == 'S') {
                        q.push(make_pair(i, make_pair(j, k)));
                        visited[i][j][k] = true;
                    }
                }
            }
        }
        int time = bfs();
        if(time == -1) {
            cout << "Trapped!" << '\n';
        } else {
            cout << "Escaped in " << time << " minute(s)." << '\n';
        }
    }

    return 0;
}