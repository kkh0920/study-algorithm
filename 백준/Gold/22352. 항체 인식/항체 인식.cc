#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[2][30][30];
bool visited[30][30];

bool possible = true;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool bfs(int si, int sj) {
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));
    visited[si][sj] = true;

    int origin = arr[0][si][sj];
    int changed = arr[1][si][sj];

    bool isChanged = origin != changed ? true : false;

    while(!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= n || nJ < 0 || nJ >= m)
                continue;
            if(visited[nI][nJ] || arr[0][nI][nJ] != origin)
                continue;
            if(arr[1][nI][nJ] != changed)
                possible = false;
            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }
    
    return isChanged;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int I = 0; I < 2; I++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> arr[I][i][j];
            }
        }
    }

    bool isChanged = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j]) continue;

            bool change = bfs(i, j);
            if((isChanged && change) || !possible) {
                cout << "NO\n";
                return 0;
            }
            if(change) isChanged = true;
        }
    }

    cout << "YES\n";

    return 0;
}