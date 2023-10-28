#include <iostream>
#include <queue>
using namespace std;

int N, K, visited[200001];

void bfs(){
    queue< pair<int, int> > q;
    q.push(make_pair(0, N));

    visited[N] = 0;
    while(!q.empty()){
        int curTime = q.front().first;
        int curPos = q.front().second;
        q.pop();

        if(curPos + 1 <= K && visited[curPos + 1] > curTime + 1){
            visited[curPos + 1] = curTime + 1;
            q.push(make_pair(curTime + 1, curPos + 1));
        }

        if(curPos - 1 >= 0 && visited[curPos - 1] > curTime + 1){
            visited[curPos - 1] = curTime + 1;
            q.push(make_pair(curTime + 1, curPos - 1));
        }

        if(curPos * 2 <= K * 2 && visited[curPos * 2] > curTime){
            visited[curPos * 2] = curTime;
            q.push(make_pair(curTime, curPos * 2));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i <= 200000; i++){
        visited[i] = 987654321;
    }

    bfs();

    cout << visited[K] << '\n';
}