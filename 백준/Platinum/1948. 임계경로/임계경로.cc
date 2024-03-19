#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< pair<int, int> > graph[10001], rGraph[10001];
int n, m, s, e, indegree[10001], maxTime[10001], road = 0;
bool visited[10001];

void solution() {
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int curNode = q.front();
        q.pop();

        int size = graph[curNode].size();
        for(int i = 0; i < size; i++) {
            int nextNode = graph[curNode][i].first;
            int nextTime = maxTime[curNode] + graph[curNode][i].second;

            if(maxTime[nextNode] <= nextTime) {
                maxTime[nextNode] = nextTime;
            }

            if(!(--indegree[nextNode])) {
                q.push(nextNode);
            }
        }
    }

    visited[e] = true;
    q.push(e);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        int size = rGraph[cur].size();
        for(int i = 0; i < size; i++) {
            int next = rGraph[cur][i].first;
            int time = rGraph[cur][i].second;
            if(maxTime[cur] - time == maxTime[next]) {
                road++;
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
}

int main() {

    cin >> n >> m;

    int a, b, t;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        graph[a].push_back(make_pair(b, t));
        rGraph[b].push_back(make_pair(a, t));
        indegree[b]++;
    }
    cin >> s >> e;

    solution();

    cout << maxTime[e] << '\n' << road << '\n';

    return 0;
}