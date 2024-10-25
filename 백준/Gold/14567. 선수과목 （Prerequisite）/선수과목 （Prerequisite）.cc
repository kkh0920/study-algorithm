#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[1001];
int N, M, indegree[1001], result[1001];

void solve() {
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    int time = 1;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int cur = q.front();
            q.pop();
            result[cur] = time;
            for(auto next : graph[cur]) {
                if(--indegree[next] == 0) {
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
    cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    solve();

    for(int i = 1; i <= N; i++) {
        cout << result[i] << " ";
    }
    cout << '\n';

    return 0;
}