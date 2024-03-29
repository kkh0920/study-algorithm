#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
int maxValue[3000], candy[30001];
bool visited[30001];

vector<int> graph[30001];
vector< pair<int, int> > v;

void bfs(int startNode) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    int sumCandy = candy[startNode];
    int personCnt = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(!visited[next]) {
                sumCandy += candy[next];
                personCnt++;
                visited[next] = true;
                q.push(next);
            }
        }
    }

    v.push_back(make_pair(personCnt, sumCandy));
}

void init() {
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            bfs(i);
        }
    }
}

void findMaxValue() {
    for(int i = 0; i < v.size(); i++) {
        int cost = v[i].first;
        int value = v[i].second;
        for(int j = k - 1; j >= cost; j--) {
            maxValue[j] = max(maxValue[j - cost] + value, maxValue[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        cin >> candy[i];
    }

    int n1, n2;
    for(int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    init();
    findMaxValue();

    cout << maxValue[k - 1] << '\n';

    /*
    
    (2, 13) : 1, 3

    (4, 26) : 2, 5, 6, 10

    (2, 24) : 4, 9

    (2, 33) : 7, 8
    
    */

    return 0;
}