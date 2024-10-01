#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
int N, M;
bool visited[101];

int getResult(int p1, int p2) {
    queue<int> q;
    q.push(p1);
    visited[p1] = true;
    int result = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int cur = q.front();
            q.pop();

            if(cur == p2) return result;

            for(auto next : graph[cur]) {
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }
        result++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int p1, p2;
    cin >> p1 >> p2;

    cin >> M;

    int parent, child;
    for(int i = 0; i < M; i++) {
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }

    cout << getResult(p1, p2) << '\n';

    return 0;
}