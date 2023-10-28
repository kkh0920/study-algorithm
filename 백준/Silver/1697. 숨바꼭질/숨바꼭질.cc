#include <bits/stdc++.h>
using namespace std;

int n, k, result;
bool visited[200000] = { false };

void bfs(){
    queue<int> q;
    q.push(n);
    visited[n] = true;
    int time = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int cur = q.front();
            q.pop();

            if(cur == k){
                result = time;
                return;
            }

            if(cur != 0 && !visited[cur - 1]){
                visited[cur - 1] = true;
                q.push(cur - 1);
            }
            if(cur < k){
                if(!visited[cur + 1]){
                    visited[cur + 1] = true;
                    q.push(cur + 1);
                }
                if(!visited[cur * 2]){
                    visited[cur * 2] = true;
                    q.push(cur * 2);
                }
            }
        }
        time++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    bfs();

    cout << result << '\n';
}