#include <iostream>
#include <vector>

#define INF 99999999

using namespace std;

int n, m;
bool visited[1001];
vector< pair<int, int> > tree[1001];

int dfs(int start, int end) {
    if(start == end) return 0;

    int dist = INF;
    for(auto next : tree[start]) {
        int nextNode = next.first;
        int nextDist = next.second;
        if(!visited[nextNode]) {
            visited[nextNode] = true;
            dist = min(dist, nextDist + dfs(nextNode, end));
            visited[nextNode] = false;
        }
    }
    
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int n1, n2, d;
    for(int i = 0; i < n - 1; i++) {
        cin >> n1 >> n2 >> d;
        tree[n1].push_back(make_pair(n2, d));
        tree[n2].push_back(make_pair(n1, d));
    }

    for(int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        visited[n1] = true;
        cout << dfs(n1, n2) << '\n';
        visited[n1] = false;
    }

    return 0;
}