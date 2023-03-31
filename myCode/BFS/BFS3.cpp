#include <iostream>
#include <queue>
using namespace std;

// bfs, 그래프이론

// *** 어떠한 수가 나왔을 때, 동일한 resultTime에 나온 다른 수와 중복체크를 하지 않음 ***

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
            // <현재 resultTime> 에 값을 넣으면서 앞으로 push할 값 중, visited된 값이 있으면 not push.
            if(q.front() > 0 && !visited[q.front() - 1])
                q.push(q.front() - 1);
            if(q.front() < K){
                if(!visited[q.front() + 1])
                    q.push(q.front() + 1);
                if(q.front() > 0 && !visited[q.front() * 2])
                    q.push(q.front() * 2);
            }
            q.pop();
        } // <현재 resultTime> 의 값 모두 push 완료.

        cnt = q.size();
        // <현재 resultTime> 에 나온 수를 처음부터 탐색하면서 목표값(K)과 visited 체크.
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