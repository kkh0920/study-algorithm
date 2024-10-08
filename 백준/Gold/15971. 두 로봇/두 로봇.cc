#include <iostream>
#include <vector>
using namespace std;

vector<int> dist;

vector< pair<int, int> > graph[100001];
int N;
bool visited[100001];

int minMove() {
    int m1 = 0, m2 = 0;
    for(int i = 1; i < dist.size(); i++) {
        m2 += dist[i];
    }
    int result = m1 + m2;
    for(int i = 1; i < dist.size(); i++) {
        m1 += dist[i - 1];
        m2 -= dist[i];
        result = min(result, m1 + m2);
    }
    return result;
}

void dfs(int cur, int dest) {
    if(cur == dest) {
        cout << minMove() << '\n';
        exit(0);
    }

    visited[cur] = true;
    for(auto next : graph[cur]) {
        if(!visited[next.first]) {
            dist.push_back(next.second);
            dfs(next.first, dest);
            dist.pop_back();
        }
    }
    visited[cur] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s1, s2;
    cin >> N >> s1 >> s2;

    int n1, n2, len;
    for(int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2 >> len;
        graph[n1].push_back({n2, len});
        graph[n2].push_back({n1, len});
    }

    dfs(s1, s2);

    return 0;
}