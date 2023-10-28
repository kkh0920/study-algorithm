#include <bits/stdc++.h>
using namespace std;

string N;
int K, M, result = 0;

void bfs(){
    M = N.size();

    if(M == 1){
        result = -1;
        return;
    }

    queue<string> q;
    q.push(N);

    while(!q.empty() && K--){
        map<string, int> visited;
        int size = q.size();
        for(int i = 0; i < size; i++){
            string cur = q.front();
            q.pop();
            
            for(int j = 0; j < M - 1; j++){
                for(int k = j + 1; k < M; k++){
                    string next = cur;
                    swap(next[j], next[k]);

                    if(next[0] == '0')
                        continue;

                    if(visited[next] == 1)
                        continue;
                    
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
    }

    if(q.empty()){
        result = -1;
        return;
    }

    while(!q.empty()){
        result = max(result, stoi(q.front()));
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    
    bfs();

    cout << result << '\n';
}