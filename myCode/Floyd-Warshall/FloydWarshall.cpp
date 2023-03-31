#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//모든 지점에서 다른 모든 지점까지의 최단거리를 구하는 알고리즘에는 다익스트라 알고리즘은 적합하지 않음.
//다익스트라 알고리즘 -> 한 지점에서 한 지점까지의 최단거리(NlogN)
//따라서 아래 코드의 겨우 최대 실행 횟수는 10000(결과 배열 초기화) * (100 * 100) * 100log100 == 100억이 넘어감.

//플로이드 워셜 알고리즘을 적용하면 모든 지점의 최단거리를 구할 수 있으므로, 
//시간복잡도는 N^3 으로 다익스트라 보다는 크지만, 데이터의 수가 적으면, 100 * 100 * 100 == 1,000,000 정도의 최대 수행 횟수를 갖게 됨.


/* 모든 지점 최단거리 구하는 문제에서의 다익스트라 사용(비효율적)
vector< pair<int, int> > graph[101];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq, pqC;
int n, m, c, resultCost[101][101];

void initResultCost(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            resultCost[i][j] = 100000 * 100;
        }
    }
}

void dijkstra(int start, int end){
    while(!pq.empty()){
        int gSize = graph[pq.top().second].size();
        for(int j = 0; j < gSize; j++){
            int nextNode = graph[pq.top().second][j].second;
            int tempCost = resultCost[start][pq.top().second] + graph[pq.top().second][j].first;
            if(tempCost < resultCost[start][nextNode]){
                pq.push(make_pair(tempCost, nextNode));
                resultCost[start][nextNode] = tempCost;
            }
        }
        pq.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int s, e, c;
    for(int i = 0; i < m; i++){
        cin >> s >> e >> c;
        graph[s].push_back(make_pair(c, e));
    }

    for(int i = 1; i <= n; i++){      
        for(int j = 1; j <= n; j++){
            initResultCost();
            pq.push(make_pair(0, i));
            resultCost[i][i] = 0;
            dijkstra(i, j);
            cout << resultCost[i][j] << ' ';
        }
        cout << '\n';
    }
}
*/

//플로이드 워셜 알고리즘
int main(){
    int n, m, cost[101][101];

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = 100000 * 100;
        }
    }

    int s, e, c;
    for(int i = 0; i < m; i++){
        cin >> s >> e >> c;
        cost[s][e] = cost[s][e] > c ? c : cost[s][e];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cost[i][j] >= 100000 * 100)
                cost[i][j] = 0;
            cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
}