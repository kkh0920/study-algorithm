#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, t, map[100][100];
bool visited[2][100][100];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

int bfs() {
    queue< pair<bool, pair<int, int> > > q;
    q.push(make_pair(false, make_pair(0, 0)));
    visited[0][0][0] = true;
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            bool sword = q.front().first;
            int curI = q.front().second.first;
            int curJ = q.front().second.second;
            q.pop();

            if(curI == n - 1 && curJ == m - 1)
                return time;

            for(int i = 0; i < 4; i++) {
                bool nSword;
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                if(nI < 0 || nI >= n || nJ < 0 || nJ >= m)
                    continue;
                nSword = map[nI][nJ] == 2 ? true : sword;
                if(!sword && map[nI][nJ] == 1 || visited[nSword][nI][nJ])
                    continue;
                visited[nSword][nI][nJ] = true;
                q.push(make_pair(nSword, make_pair(nI, nJ)));
            }
        }
        if(++time > t) return -1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> t;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int result = bfs();
    if(result == -1) {
        cout << "Fail" << '\n'; 
    } else {
        cout << result << '\n';
    }

    return 0;
}