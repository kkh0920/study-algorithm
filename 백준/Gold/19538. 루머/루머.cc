#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, result[200001], infected[200001];
vector<int> graph[200001];
bool visited[200001];

queue<int> q;

void bfs() {
    int time = 1;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int cur = q.front(); q.pop();
            for(auto next : graph[cur]) {
                if(visited[next]) continue;
                
                int percent = (100 * ++infected[next]) / graph[next].size();
                if(percent >= 50) {
                    result[next] = time;
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        time++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    int num = 0;
    for(int i = 1; i <= n; i++) {
        result[i] = -1;
        while(1) {
            cin >> num;
            if(num == 0) break;
            graph[i].push_back(num);
        }
    }

    cin >> m;

    int f;
    for(int i = 0; i < m; i++) {
        cin >> f;
        result[f] = 0;
        visited[f] = true;
        q.push(f);
    }

    bfs();

    for(int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}