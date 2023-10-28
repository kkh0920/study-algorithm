#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue< pair<int, int> > q;
vector< pair<int, int> > graph[10001];
int N, indegree[10001], result = 0, minCost = 101;

void topologicalSort(){
	while(!q.empty()){
		int qSize = q.size();
		int mc = 101;
		for(int i = 0; i < qSize; i++){
			int curNode = q.front().second;
			int cost = q.front().first;
			q.pop();

			if(cost - minCost > 0){
				q.push(make_pair(cost - minCost, curNode));
				mc = min(mc, cost - minCost);
				continue;
			}

			int size = graph[curNode].size();
			for(int j = 0; j < size; j++){
				int nextNode = graph[curNode][j].second;
				int nextCost = graph[curNode][j].first;

				if(--indegree[nextNode] == 0){
					q.push(make_pair(nextCost, nextNode));
					mc = min(mc, nextCost);
				}
			}
		}
		result += minCost;
		minCost = mc;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N;

	int cost, indegree_num, prevNode;
	for(int i = 1; i <= N; i++){
		cin >> cost >> indegree_num;
		if(indegree_num == 0)
			q.push(make_pair(cost, i));

		minCost = min(minCost, cost);

		indegree[i] = indegree_num;
		for(int j = 0; j < indegree_num; j++){
			cin >> prevNode;
			graph[prevNode].push_back(make_pair(cost, i));
		}
	}

	topologicalSort();

	cout << result << '\n';
}	