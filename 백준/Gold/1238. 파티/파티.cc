#include <iostream>
#include <queue>
#include <vector>
#define INF 100000000
using namespace std;

vector< pair<int, int> > graph[2][1001];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
int weight[1001], result[1001], N, M, X, s, e, t;

void dijkstra(int revNum, int start){
    fill_n(weight, N + 1, INF);
    weight[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int size = graph[revNum][pq.top().second].size();
        for(int i = 0; i < size; i++){
            int nextWeight = graph[revNum][pq.top().second][i].first;
            int nextNode = graph[revNum][pq.top().second][i].second;
            if(weight[nextNode] > pq.top().first + nextWeight){
                weight[nextNode] = pq.top().first + nextWeight;
                pq.push(make_pair(weight[nextNode], nextNode));
            }
        }
        pq.pop();
    }
    for(int i = 1; i <= N; i++)
        result[i] += weight[i];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    for(int i = 0; i < M; i++){
        cin >> s >> e >> t;
        graph[0][s].push_back(make_pair(t, e));
        graph[1][e].push_back(make_pair(t, s));
    }
    
    fill_n(result, N + 1, 0);
    
    dijkstra(0, X);
    dijkstra(1, X);
    
    int maxT = 0;
    for(int i = 1; i <= N; i++){
        maxT = max(maxT, result[i]);
    }
    
    cout << maxT << '\n';
}