#include <iostream>
#include <map>
using namespace std;

map< char, pair<int, int> > dir = {
    {'U', {-1, 0}},
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}}
};

int N, M;
char maze[500][501];
bool visited[500][500];

bool dfs(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= M) return true;
    
    if(maze[x][y] == 'O') return true;
    if(maze[x][y] == 'X') return false;
    
    if(visited[x][y]) return false;

    visited[x][y] = true;

    int nx = x + dir[maze[x][y]].first;
    int ny = y + dir[maze[x][y]].second;
    bool escape = dfs(nx, ny);

    visited[x][y] = false;

    maze[x][y] = (escape ? 'O' : 'X');
    
    return escape;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }

    int result = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(dfs(i, j)) result++;
        }
    }

    cout << result << '\n';

    return 0;
}