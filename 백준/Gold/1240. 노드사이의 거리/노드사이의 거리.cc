#include <iostream>
#include <vector>

#define INF 99999999

using namespace std;

int n, m, dist[1001][1001];
bool visited[1001];
vector<int> tree[1001];

int dfs(int start, int end) {
    if(start == end)
        return dist[start][end];

    int d = INF;
    for(auto next : tree[start]) {
        if(!visited[next]) {
            visited[next] = true;
            d = min(d, dist[start][next] + dfs(next, end));
            visited[next] = false;
        }
    }
    
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }   
    }

    int n1, n2, d;
    for(int i = 0; i < n - 1; i++) {
        cin >> n1 >> n2 >> d;
        
        dist[n1][n2] = d;
        dist[n2][n1] = d;

        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    for(int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        visited[n1] = true;
        cout << dfs(n1, n2) << '\n';
        visited[n1] = false;
    }

    return 0;
}