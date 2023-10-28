#include <bits/stdc++.h>
using namespace std;

queue< pair<int, int> > q;
vector<int> reverseGraph[1001];
int t, n, k, w, cost[1001], resCost[1001], sum = 0;

void bfs(){
    q.push(make_pair(w, cost[w]));
    resCost[w] = cost[w];
    while(!q.empty()){
        int curNode = q.front().first;
        int curCost = q.front().second;
        q.pop();
      
        if(curCost < resCost[curNode] || curCost == sum)
            continue;

        int i, size = reverseGraph[curNode].size();
        for(i = 0; i < size; i++){
            int nextNode = reverseGraph[curNode][i];
            if(nextNode == w || resCost[nextNode] > resCost[curNode] + cost[nextNode])
                continue;
            resCost[nextNode] = resCost[curNode] + cost[nextNode];
            q.push(make_pair(nextNode, resCost[nextNode]));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> k;
        sum = 0;
        for(int j = 1; j <= n; j++){
            cin >> cost[j];
            sum += cost[j];
            resCost[j] = 0;
        }
        int s, e;
        for(int j = 0; j < k; j++){
            cin >> s >> e;
            reverseGraph[e].push_back(s);
        }
        cin >> w;

        bfs();

        int result = 0;
        for(int i = 1; i <= n; i++){
            result = max(result, resCost[i]);
            reverseGraph[i].clear();
        }

        cout << result<< '\n';
    }
}