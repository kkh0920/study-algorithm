#include <bits/stdc++.h>
using namespace std;

vector<int> graph[32001];
int N, M, indegree[32001] = { 0, };

void topologicalSort(){
    priority_queue< int, vector<int>, greater<int> > pq;
    for(int i = 1; i <= N; i++){
        if(!indegree[i])
            pq.push(i);
    }
    while(!pq.empty()){
        int curNum = pq.top();
        pq.pop();

        cout << curNum << ' ';

        int size = graph[curNum].size();
        for(int i = 0; i < size; i++){
            int nextNum = graph[curNum][i];
            if(!--indegree[nextNum])
                pq.push(nextNum);
        }
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int s, e;
    for(int i = 0; i < M; i++){
        cin >> s >> e;
        graph[s].push_back(e);
        indegree[e]++;
    }

    topologicalSort();
}