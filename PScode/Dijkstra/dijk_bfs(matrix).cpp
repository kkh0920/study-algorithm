#include <bits/stdc++.h>
#define INF 500 * 1000 + 1
using namespace std;

// BOJ 5719

// 거의 최단경로(인접 행렬)

// 1. 다익스트라를 이용해서 거리가 작은 값으로 갱신될때마다 이전 노드를 갱신해준다.

// 2. 최단거리가 여러개일 수 있으므로, 갱신되는 거리와 현재 거리가 같을 때는 이전 노드를 추가해주고 패스한다
//    -> prevNode[N]에는 N의 이전노드의 길이가 가장 짧은 형태로 저장된다.(최단거리, 여러개 가능)

// 3. bfs 알고리즘을 통해, 저장된 이전 노드(prevNode)를 활용하여, 도착점에서 시작까지 역순으로 최단 거리 간선을 지워준다.
//    -> 인접 행렬 : matrixGraph[prev][cur] = INF 로 곧바로 그래프의 최단 거리 간선를 지워줄 수 있다.

// 4. 그래프의 최단거리 간선을 지워주었으므로, 다시 다익스트라 알고리즘을 실행한다.

// 5. 이후 나오는 dist[D] 값이 거의 최단경로이다.

vector<int> graph[500];
int matrixGraph[500][500];

vector<int> prevNode[500];

int N, M, S, D;
int dist[500];
bool visited[500];

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j)
                matrixGraph[i][j] = 0;
            else
                matrixGraph[i][j] = INF;
        }
    }

    for(int i = 0; i < N; i++){
        graph[i].clear();
        prevNode[i].clear();
    }
}

void dijkstra(){
    priority_queue< pair<int, int>, vector< pair<int ,int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, S));

    fill(dist, dist + N, INF);
    dist[S] = 0;
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight = pq.top().first;
        pq.pop();

        if(curWeight > dist[curNode])
            continue;
        
        int size = graph[curNode].size();
        for(int i = 0; i < size; i++){
            int nextNode = graph[curNode][i];
            int nextWeight = matrixGraph[curNode][nextNode];

            if(dist[nextNode] > dist[curNode] + nextWeight){
                prevNode[nextNode].clear();
                prevNode[nextNode].push_back(curNode);

                dist[nextNode] = dist[curNode] + nextWeight;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
            else if(dist[nextNode] == dist[curNode] + nextWeight)
                prevNode[nextNode].push_back(curNode);
        }
    }
}

void removePath(){
    queue<int> q;
    q.push(D);

    fill(visited, visited + N, false);
    visited[D] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int size = prevNode[cur].size();
        for(int i = 0; i < size; i++){
            int prev = prevNode[cur][i];
            matrixGraph[prev][cur] = INF;
            if(visited[prev])
                continue;
            visited[prev] = true;
            q.push(prev);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        cin >> N >> M; // 2 <= N <= 500, 1 <= M <= 10000
        if(N == 0 || M == 0)
            break;

        init();

        cin >> S >> D; // S != D, 0 <= (S, D) < N

        int U, V, P; // U != V, 1 <= P <= 1000
        for(int i = 0; i < M; i++){
            cin >> U >> V >> P;
            graph[U].push_back(V);
            matrixGraph[U][V] = P;
        }

        dijkstra();

        removePath();

        dijkstra();

        if(dist[D] == INF)
            cout << -1 << '\n';
        else
            cout << dist[D] << '\n';
    }
}