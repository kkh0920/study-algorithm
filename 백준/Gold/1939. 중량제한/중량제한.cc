#include <bits/stdc++.h>
#define MAXN 10001
#define MAXW 1000000000

using namespace std;

vector< pair<int, int> > graph[MAXN];
int N, M, A, B;
int result;
bool visited[MAXN];

bool isPossible(int limit){
    queue<int> q;
    q.push(A);

    fill(visited, visited + (N + 1), false);
    visited[A] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int size = graph[cur].size();
        for(int i = 0; i < size; i++){
            int next = graph[cur][i].second;
            int nextWeight = graph[cur][i].first;
            if(visited[next] || nextWeight < limit)
                continue;
            if(next == B){
                result = limit;
                return true;
            }
            visited[next] = true;
            q.push(next);
        }
    }
    return false;
}

void binarySearch(){
    int maxW = MAXW, minW = 1;
    while(maxW >= minW){
        int mid = (maxW + minW) / 2;
        if(isPossible(mid))
            minW = mid + 1;
        else
            maxW = mid - 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));
    }
    cin >> A >> B;

    binarySearch();

    cout << result << '\n';
}