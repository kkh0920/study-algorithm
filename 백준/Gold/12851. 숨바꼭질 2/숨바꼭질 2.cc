#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
bool visited[200001] = { false };
int N, K, resultTime = 0, resultCnt = 0;

void bfs(){
    int cnt = 1;
    q.push(N);
    visited[N] = true;
    resultCnt += N == K ? 1 : 0;
    while(!q.empty()){
        resultTime++;
        for(int i = 0; i < cnt; i++){
            if(resultCnt){
                resultTime--;
                return;
            }
            if(q.front() > 0 && !visited[q.front() - 1])
                q.push(q.front() - 1);
            if(q.front() < K){
                if(!visited[q.front() + 1])
                    q.push(q.front() + 1);
                if(q.front() > 0 && !visited[q.front() * 2])
                    q.push(q.front() * 2);
            }
            q.pop();
        }
        cnt = q.size();
        for(int i = 0; i < cnt; i++){
            q.push(q.front());
            resultCnt += q.front() == K ? 1 : 0;
            visited[q.front()] = true;
            q.pop();
        }
    }
}

int main(){
    cin >> N >> K;
    bfs();
    cout << resultTime << '\n';
    cout << resultCnt << '\n';
}