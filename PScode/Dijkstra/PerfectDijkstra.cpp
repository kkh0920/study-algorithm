#include <iostream>
#include <queue>
#include <vector>
#define INF 500000000
#define MAXN 1001

using namespace std;

vector< pair<int, int> > graph[MAXN];
int n, m, s, e, w, prevNode[MAXN] = { 0, }, dist[MAXN];

// 정확한 다익스트라.
// 다익스트라 알고리즘을 수행할 때는 우선순위 큐를 사용하게 되는데,
// 이 때, 내가 기존에 짰던 코드처럼 pq안에 들어있던 값을 "고정"시켜놓지 않으면,
// for문을 돌면서 pq값이 계속 변하게 된다.
// 이 말은 즉슨, 사전에 size값은 고정시켜놓았기 때문에, 만약 변경된 pq의 그래프 size가,
// 이전에 고정해놓았던 size값보다 커지게 되면, outOfBound 런타임 에러가 발생이 된다.

// 그럼 씨발 왜 내가 지금까지 짜왔던 다익스트라 코드는 잘 작동되었던 거지?
// 진짜 너무 억울하다.

// 그래도 이번 기회를 통해서 내가 짜왔던 다익스트라 코드의 치명적이 문제점을 발견했으니,
// 이것도 값진 경험이라고 생각하련다. 하.

void dijkstra(){
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curWeight = pq.top().first;
        pq.pop();

        if(curWeight > dist[curNode])
            continue;

        for(int i = 0; i < graph[curNode].size(); i++){
            int nextNode = graph[curNode][i].first;
            int nextWeight = graph[curNode][i].second;
            if(dist[nextNode] > curWeight + nextWeight){
                dist[nextNode] = curWeight + nextWeight;
                prevNode[nextNode] = curNode;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e, w));
    }
    cin >> s >> e;

    fill_n(dist, n + 1, INF);

    dijkstra();

    vector<int> route;
    int temp = e;
    while(temp != s){
        route.push_back(temp);
        temp = prevNode[temp];
    }

    cout << dist[e] << '\n';
    cout << route.size() + 1<< '\n';
    cout << s <<  ' ';
    for(int i = route.size() - 1; i >= 0; i--){
        cout << route[i] << ' ';
    }
    cout << '\n';
}