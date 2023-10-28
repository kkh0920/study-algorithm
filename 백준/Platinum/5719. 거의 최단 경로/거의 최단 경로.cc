#include <bits/stdc++.h>
#define INF 500 * 1000 + 1
using namespace std;

vector<int> prevNode[500];
vector< pair< bool, pair<int, int > > > graph[500];
int N, M, S, D, shortestDist;
int dist[500];
bool visited[500];

void init(){
    for(int i = 0; i < N; i++){
        graph[i].clear();
        prevNode[i].clear();
        visited[i] = false;
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
            int nextNode = graph[curNode][i].second.second;
            int nextWeight = graph[curNode][i].second.first;
            bool isMove = graph[curNode][i].first;

            if(isMove && dist[nextNode] > dist[curNode] + nextWeight){
                prevNode[nextNode].clear();
                prevNode[nextNode].push_back(curNode);

                dist[nextNode] = dist[curNode] + nextWeight;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
            else if(isMove && dist[nextNode] == dist[curNode] + nextWeight)
                prevNode[nextNode].push_back(curNode);
        }
    }
}

void removePath(){
    queue<int> q;
    q.push(D);
    visited[D] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int size = prevNode[cur].size();
        for(int i = 0; i < size; i++){
            int gSize = graph[prevNode[cur][i]].size();
            for(int j = 0; j < gSize; j++){
                int next = prevNode[cur][i];
                int parent = graph[next][j].second.second;
                if(parent == cur){
                    if(!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                    graph[next][j].first = false;
                    break;
                }
            }
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
            graph[U].push_back(make_pair(true, make_pair(P, V)));
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