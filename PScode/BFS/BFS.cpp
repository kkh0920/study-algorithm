#include <iostream>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int N, M, result[101] = { 0 };
bool check[101];
queue< pair <int, int> > q;
vector<int> relation[101];

void bfs(int s){
    int cnt = 1;
    memset(check, false, sizeof(bool) * 101);
    q.push(make_pair(s, cnt));
    while(q.size() != 0){
        for(int i = 0; i < relation[q.front().first].size(); i++){
            if(!check[relation[q.front().first][i]]){
                q.push(make_pair(relation[q.front().first][i], cnt + 1));
                check[relation[q.front().first][i]] = true;
                result[s] += cnt;
            }
        }
        q.pop();
        cnt = q.front().second;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, min = 200, minI;
    
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        bfs(i);
        if(min > result[i]){
            min = result[i];
            minI = i;
        }
    }

    cout << minI << '\n';
}