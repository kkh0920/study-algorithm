#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue< pair<int, int> > q;
vector< pair<int, int> > graph[501];
int N, indegree[501], minCost = 100001, result[501];

void topologicalSort(){
    int res = 0;
    while(!q.empty()){
        int size = q.size();
        int mc = 100001;

        res += minCost;
        for(int i = 0; i < size; i++){
            int curNode = q.front().second;
            int cost = q.front().first;
            q.pop();

            if(cost - minCost != 0){
                q.push(make_pair(cost - minCost, curNode));
                mc = min(mc, cost - minCost);
                continue;
            }

            result[curNode] = res;

            int gSize = graph[curNode].size();
            for(int j = 0; j < gSize; j++){
                int nextNode = graph[curNode][j].second;
                int nextCost = graph[curNode][j].first;

                if(--indegree[nextNode] == 0){
                    q.push(make_pair(nextCost, nextNode));
                    mc = min(mc, nextCost);
                }
            }
        }
        minCost = mc;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int cost, prevNode = 0;
    for(int i = 1; i <= N; i++){
        cin >> cost;

        while(1){
            cin >> prevNode;
            if(prevNode == -1)
                break;
            graph[prevNode].push_back(make_pair(cost, i));
            indegree[i]++;
        }

        if(indegree[i] == 0){
            q.push(make_pair(cost, i));
            minCost = min(minCost, cost);
        }
    }

    topologicalSort();

    for(int i = 1; i <= N; i++){
        cout << result[i] << '\n';
    }
}