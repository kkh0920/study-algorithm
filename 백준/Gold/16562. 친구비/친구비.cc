#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[10001];
int n, m, k, cost[10001];
bool checked[10001];

int getMinCost(int start) {
    queue<int> q;
    q.push(start);
    checked[start] = true;
    int mCost = cost[start];
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int size = graph[cur].size();
        for(int i = 0; i < size; i++) {
            int next = graph[cur][i];
            if(!checked[next]) {
                mCost = min(mCost, cost[next]);
                checked[next] = true;
                q.push(next);
            }
        }
    }
    return mCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    int v, w;
    for(int i = 0; i < m; i++) {
        cin >> v >> w;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    int result = 0;
    for(int i = 1; i <= n; i++) {
        if(!checked[i]) {
            result += getMinCost(i);
        }
    }

    if(result > k) {
        cout << "Oh no\n";
    } else {
        cout << result << '\n';
    }

    return 0;
}