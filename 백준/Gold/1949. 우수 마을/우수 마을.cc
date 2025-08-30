#include <iostream>
#include <vector>
using namespace std;

int N, resident[10001], maxResident[2][10001];
bool visited[10001];
vector<int> tree[10001];

int dp(int node, bool isSuperior) {
    if (visited[node]) {
        return 0;
    }
    if (maxResident[isSuperior][node] != -1) {
        return maxResident[isSuperior][node];
    }
    visited[node] = true;

    int result = 0;
    int size = tree[node].size();

    if (isSuperior) {
        result += resident[node];
        for (int i = 0; i < size; i++) {
            result += dp(tree[node][i], false);
        }
    } else {
        for (int i = 0; i < size; i++) {
            result += max(
                dp(tree[node][i], true), 
                dp(tree[node][i], false)
            );
        }
    }

    visited[node] = false;

    return maxResident[isSuperior][node] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> resident[i];
        maxResident[0][i] = -1;
        maxResident[1][i] = -1;
    }

    int u, v;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << max(dp(1, true), dp(1, false)) << '\n';

    return 0;
}