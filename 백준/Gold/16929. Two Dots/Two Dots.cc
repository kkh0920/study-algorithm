#include <iostream>
using namespace std;

int n, m;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char map[50][50];
bool visited[50][50];

bool isCycle(int curI, int curJ, int prevI, int prevJ) {
    for(int i = 0; i < 4; i++) {
        int nI = curI + dx[i];
        int nJ = curJ + dy[i];
        if(nI < 0 || nI >= n || nJ < 0 || nJ >= m)
            continue;
        if(map[nI][nJ] != map[curI][curJ])
            continue;
        if(visited[nI][nJ]) {
            if(nI != prevI || nJ != prevJ) {
                return true;
            }
            continue;
        }
        visited[nI][nJ] = true;
        bool cycle = isCycle(nI, nJ, curI, curJ);
        visited[nI][nJ] = false;
        if(cycle) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = true;
            if(isCycle(i, j, -1, -1)) {
                cout << "Yes\n";
                return 0;
            }
            visited[i][j] = false;
        }
    }

    cout << "No\n";

    return 0;
}