#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
int n, m, res[101];
bool visited[101];

void initVisited() {
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);

    initVisited();
    visited[s] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        int size = graph[cur].size();
        for(int i = 0; i < size; i++) {
            int next = graph[cur][i];
            if(!visited[next]) {
                visited[next] = true;
                res[s]--;
                res[next]--;
                q.push(next);
            }
        }
    }   
}

int main() {
    cin >> n >> m;

    int l, s;
    for(int i = 0; i < m; i++) {
        cin >> l >> s;
        graph[l].push_back(s);
    }

    for(int i = 1; i <= n; i++) {
        res[i] = n - 1;
    }

    for(int i = 1; i <= n; i++) {
        bfs(i);
    }

    for(int i = 1; i <= n; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}