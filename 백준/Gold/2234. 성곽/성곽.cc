#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[2500];
int n, m, map[50][50], temp[50][50], area[2500], result1 = 0, result2 = 0, result3 = 0;
bool visited[50][50];
int dx[4] = { 0, -1, 0, 1 }, dy[4] = { -1, 0, 1, 0 };

int bfs1(int si, int sj) {
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));
    visited[si][sj] = true;
    temp[si][sj] = result1;
    int cnt = 1;
    while(!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= m || nJ < 0 || nJ >= n)
                continue;
            if(visited[nI][nJ] || map[curI][curJ] & (1 << i))
                continue;
            cnt++;
            visited[nI][nJ] = true;
            temp[nI][nJ] = result1;
            q.push(make_pair(nI, nJ));
        }
    }
    return cnt;
}

void bfs2(int si, int sj) {
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));
    visited[si][sj] = true;
    while(!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= m || nJ < 0 || nJ >= n || visited[nI][nJ])
                continue;
            if(temp[nI][nJ] != temp[si][sj]) {
                graph[temp[si][sj]].push_back(temp[nI][nJ]);
                continue;
            }
            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                area[result1] = bfs1(i, j);
                result2 = max(result2, area[result1++]);
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                bfs2(i, j);
            }
        }
    }

    for(int i = 0; i < result1; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            result3 = max(result3, area[i] + area[graph[i][j]]);
        }
    }

    cout << result1 << '\n' << result2 << '\n' << result3 << '\n';

    return 0;
}