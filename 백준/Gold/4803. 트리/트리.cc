#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, result = 0, parent[501];
vector<int> graph[501];
bool visited[501][501], checked[501];

void init() {
    for(int i = 1; i <= n; i++) {
        graph[i].clear();
        parent[i] = i;
        checked[i] = false;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
    result = 0;
}

int getRoot(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = getRoot(parent[x]);
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    checked[start] = true;
    bool isCycle = false;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int next : graph[cur]) {
            if(visited[cur][next] || visited[next][cur]) {
                continue;
            }
            visited[cur][next] = true;
            visited[next][cur] = true;

            int rootCur = getRoot(cur);
            int rootNext = getRoot(next);
            if(rootCur == rootNext) {
                isCycle = true;
                continue;
            }

            if(rootCur < rootNext) {
                parent[next] = rootCur;
            } else {
                parent[cur] = rootNext;
            }
            checked[next] = true;
            q.push(next);
        }
    }
    if(!isCycle) result++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, e, c = 1;
    while(1) {
        cin >> n >> m;
        if(n == 0) break;
        init();
        for(int i = 0; i < m; i++) {
            cin >> s >> e;
            graph[s].push_back(e);
            graph[e].push_back(s);
        }
        for(int i = 1; i <= n; i++) {
            if(!checked[i]) {
                bfs(i);
            }
        }
        cout << "Case " << c++ << ": ";
        switch(result) {
            case 0 :
                cout << "No trees.\n";
                break;
            case 1 : 
                cout << "There is one tree.\n";
                break;
            default:
                cout << "A forest of " << result << " trees.\n";
                break;
        }
    }

    return 0;
}