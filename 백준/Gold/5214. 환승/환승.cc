#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K, M;
vector<int> graph[101001];
bool visited[101001];

queue<int> q;

int bfs() {
    q.push(1);
    visited[1] = true;

    int result = 2;
    while (!q.empty()) {
        int size = q.size();
        while(size--) {
            int cur = q.front();
            q.pop();

            if (cur == N) {
                return result / 2;
            }
            for (auto next : graph[cur]) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        result++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> M;

    int num;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> num;
            graph[i + N].push_back(num);
            graph[num].push_back(i + N);
        }
    }

    cout << bfs() << '\n';

    return 0;
}