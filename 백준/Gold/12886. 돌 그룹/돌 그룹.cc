#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue< pair<int, pair<int, int> > > q;
bool visited[1501][1501];

void bfs() {
    while(!q.empty()) {
        int g[3];
        g[0] = q.front().first;
        g[1] = q.front().second.first;
        g[2] = q.front().second.second;
        q.pop();

        if(g[0] == g[1] && g[1] == g[2]) {
            cout << 1 << '\n';
            return;
        }

        sort(g, g + 3);

        if(g[0] != g[1] && !visited[g[0] * 2][g[1] - g[0]]) {
            visited[g[0] * 2][g[1] - g[0]] = true;
            visited[g[1] - g[0]][g[0] * 2] = true;
            q.push({g[0] * 2, {g[1] - g[0], g[2]}});
        }
        if(g[0] != g[2] && !visited[g[0] * 2][g[2] - g[0]]) {
            visited[g[0] * 2][g[2] - g[0]] = true;
            visited[g[2] - g[0]][g[0] * 2] = true;
            q.push({g[0] * 2, {g[2] - g[0], g[1]}});
        }
        if(g[1] != g[2] && !visited[g[1] * 2][g[2] - g[1]]) {
            visited[g[1] * 2][g[2] - g[1]] = true;
            visited[g[2] - g[1]][g[1] * 2] = true;
            q.push({g[1] * 2, {g[2] - g[1], g[0]}});
        }
    }
    cout << 0 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    
    cin >> a >> b >> c;
    
    visited[a][b] = true;
    visited[b][a] = true;
    visited[a][c] = true;
    visited[c][a] = true;
    visited[b][c] = true;
    visited[c][b] = true;

    q.push({a, {b, c}});

    bfs();

    return 0;
}