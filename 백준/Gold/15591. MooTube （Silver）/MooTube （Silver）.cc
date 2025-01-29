#include <iostream>
#include <vector>
using namespace std;

int N, Q;
bool visited[5001];
vector< pair<int, int> > graph[5001];

int dfs(int criteria, int node, int usado) {
    if(usado < criteria || visited[node]) {
        return 0;
    }
    visited[node] = true;

    int count = 1;
    for(auto next : graph[node]) {
        count += dfs(criteria, next.first, min(usado, next.second));
    }
    
    visited[node] = false;
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;

    int p, q, r;
    for(int i = 0; i < N - 1; i++) {
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }

    int k, v;
    for(int i = 0; i < Q; i++) {
        cin >> k >> v;
        cout << dfs(k, v, 1000000001) - 1 << '\n';
    }

    return 0;
}