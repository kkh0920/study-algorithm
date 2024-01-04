#include <iostream>
#include <queue>
using namespace std;

vector<int> graph[32001];
int N, M, indegree[32001];

void topologicalSort() {
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int curNode = q.front();
        int nextCount = graph[curNode].size();
        q.pop();

        for(int i = 0; i < nextCount; i++) {
            int nextNode = graph[curNode][i];
            if((--indegree[nextNode]) == 0) {
                q.push(nextNode);
            }
        }

        cout << curNode << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int node1, node2;
    for(int i = 0; i < M; i++) {
        cin >> node1 >> node2;
        indegree[node2]++;
        graph[node1].push_back(node2);
    }

    topologicalSort();

    return 0;
}