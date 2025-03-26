#include <iostream>
#include <vector>
using namespace std;

#define INF 1e10

long long cost[501];
vector< pair< pair<int, int>, int > > edge;

void init(int);
void inputEdge(int);
void bellmanFord(int);
void dfs(int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    init(n);
    inputEdge(m);
    bellmanFord(n);

    return 0;
}

void init(int n) {
    cost[1] = 0;
    for(int i = 2; i <= n; i++) {
        cost[i] = INF;
    }
}

void inputEdge(int m) {
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge.push_back({{a, b}, c});
    }
}

void bellmanFord(int n) {
    int cnt = n - 1;
    while(cnt--) {
        for(auto e : edge) {
            int from = e.first.first;
            int to = e.first.second;
            int time = e.second;
            if(cost[from] == INF) {
                continue;
            }
            if(cost[to] > cost[from] + time) {
                cost[to] = cost[from] + time;
            }
        }
    }
    for(auto e : edge) {
        int from = e.first.first;
        int to = e.first.second;
        int time = e.second;
        if(cost[from] == INF) {
            continue;
        }
        if(cost[to] > cost[from] + time) {
            cout << -1 << '\n';
            return;
        }
    }
    for(int i = 2; i <= n; i++) {
        cout << (cost[i] == INF ? -1 : cost[i]) << '\n';
    }
}