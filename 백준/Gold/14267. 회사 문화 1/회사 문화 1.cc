#include <iostream>
#include <queue>
using namespace std;

int n, m, result[100001];
vector<int> graph[100001];

void solution() {
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto u : graph[cur]) {
            result[u] += result[cur];
            q.push(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int b;
    for(int i = 1; i <= n; i++) {
        cin >> b;
        if(b != -1) graph[b].push_back(i);
    }

    int s, w;
    for(int i = 0; i < m; i++) {
        cin >> s >> w;
        result[s] += w;
    }

    solution();

    for(int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}