#include <bits/stdc++.h>
using namespace std; 

// BOJ 17472
// 최소 신장 트리(MST) : 크루스칼 알고리즘

priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, greater< pair<int, pair<int, int> > > > pq;

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int N, M, arr[10][10], islandCnt = 1, result = 0;
int graph[100][100], parent[100];
bool visited[10][10];

void bfs(int cI, int cJ){
    queue< pair<int, int> > q;
    q.push(make_pair(cI, cJ));

    visited[cI][cJ] = true;
    arr[cI][cJ] = islandCnt;

    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= M)
                continue;
            if(visited[nI][nJ] || arr[nI][nJ] == 0)
                continue;
            visited[nI][nJ] = true;
            arr[nI][nJ] = islandCnt;
            q.push(make_pair(nI, nJ));
        }
    }

    islandCnt++;
}


void search(int cI, int cJ, int num){
    for(int k = 0; k < 4; k++){
        int nI = cI;
        int nJ = cJ;
        int dist = 0;
        while(1){
            nI += dx[k];
            nJ += dy[k];

            if(nI < 0 || nI >= N || nJ < 0 || nJ >= M)
                break;
            if(arr[nI][nJ] == num)
                break;
            if(arr[nI][nJ] != num && arr[nI][nJ] != 0){
                if(dist > 1){
                    graph[num][arr[nI][nJ]] = min(graph[num][arr[nI][nJ]], dist);
                }
                break;
            }

            dist++;
        }
    }
}

int findRoot(int x){
    if(parent[x] == x)
        return x;

    // 경로 압축(재귀 실행 횟수 감소)
    return parent[x] = findRoot(parent[x]);
}

void unionRoot(int x, int y){
    x = findRoot(x);
    y = findRoot(y);

    if(x != y)
        parent[y] = x;
}

void kruskal(){
    while(!pq.empty()){
        int weight = pq.top().first;
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;
        pq.pop();

        if(findRoot(node1) == findRoot(node2))
            continue;
        
        unionRoot(node1, node2);

        result += weight;
    }

    // 모든 섬이 연결되어있지 않으면 result에 -1을 대입
    int p = findRoot(1);
    for(int i = 2; i <= islandCnt; i++){
        if(p != findRoot(i)){
            result = -1;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 0. Input
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            visited[i][j] = false;
        }
    }

    // 1. 입력받은 배열을 탐색해서 섬 마다 고유의 숫자를 지정.
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && arr[i][j] == 1)
                bfs(i, j);
        }
    }
    islandCnt--;

    // 1.1 계산된 섬의 개수만큼, parent와 인접 행렬 그래프 초기화
    for(int i = 1; i <= islandCnt; i++){
        parent[i] = i;
    }
    for(int i = 1; i <= islandCnt; i++){
        for(int j = 1; j <= islandCnt; j++){
            graph[i][j] = 100;
        }
    }

    // 2. 각 섬의 모든 블록에 대해 {상 하 좌 우} 방향의 탐색을 실시
    //      -> 한 섬에서 다른 섬으로 향하는, 최소 길이의 정보를 담는 그래프를 생성
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] != 0)
                search(i, j, arr[i][j]);
        }
    }

    // 3. 그래프의 모든 간선을 우선순위 큐에 push(크루스칼 알고리즘의 그리디(greedy)적인 부분을 해결)
    for(int i = 1; i <= islandCnt; i++){
        for(int j = 1; j <= islandCnt; j++){
            if(graph[i][j] != 100)
                pq.push(make_pair(graph[i][j], make_pair(i, j)));
        }
    }

    // 4. 최소 루트 계산
    kruskal();
    
    cout << result << '\n';
}