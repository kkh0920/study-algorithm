#include <iostream>
using namespace std;

int n, m, k;
string str[1000];

char map[11][11];
int mem[5][11][11];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void init(int len) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                mem[i][j][k] = -1;
            }
        }
    }
}

int dfs(int x, int y, int time, int idx) {
    if(time + 1 >= str[idx].length()) return 1;
    if(mem[time][x][y] != -1) return mem[time][x][y];

    int sum = 0;
    for(int i = 0; i < 8; i++) {
        int nX = x + dx[i], nY = y + dy[i];
        if(nX < 0) nX = n - 1; if(nX >= n) nX = 0;
        if(nY < 0) nY = m - 1; if(nY >= m) nY = 0;
        if(map[nX][nY] != str[idx][time + 1]) continue;
        sum += dfs(nX, nY, time + 1, idx);
    }

    return mem[time][x][y] = sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int index = 0; index < k; index++) {
        cin >> str[index];

        init(str[index].length());

        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] == str[index][0]) {
                    result += dfs(i, j, 0, index);
                }
            }
        }

        cout << result << '\n';
    }

    return 0;
}