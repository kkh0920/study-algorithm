#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000

using namespace std;

//특정한 최단경로

vector< pair<int, int> > graph[801];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
int N, E, a, b, c, v1, v2, weight[801];

void initWeight(){
    for(int i = 1; i <= N; i++){
        weight[i] = INF;
    }
}

void dijkstra(int start){
    initWeight();
    pq.push(make_pair(0, start));
    weight[start] = 0;
    while(!pq.empty()){
        int size = graph[pq.top().second].size();
        for(int i = 0; i < size; i++){
            int nextNode = graph[pq.top().second][i].second;
            int nextWeight = graph[pq.top().second][i].first;
            if(weight[nextNode] > weight[pq.top().second] + nextWeight){
                weight[nextNode] = weight[pq.top().second] + nextWeight;
                pq.push(make_pair(weight[nextNode], nextNode));
            }
        }
        pq.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E;

    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));
    }
    
    cin >> v1 >> v2;

    dijkstra(1);
    //1 -> v1
    int V2 = weight[v1];
    //1 -> v2
    int V1 = weight[v2];

    //1 -> v1 -> v2 -> N
    dijkstra(v1);
    V2 += weight[v2];
    dijkstra(v2);
    V2 += weight[N];

    //1 -> v2 -> v1 -> N
    dijkstra(v2);
    V1 += weight[v1];
    dijkstra(v1);
    V1 += weight[N];

    //최단 거리 출력
    int result = V1 < V2 ? V1 : V2;
    if(result >= INF)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}