#include <iostream>
#include <queue>
using namespace std;

int S, result = 0;
bool checked[2000][1000];

void bfs(){
    // 현재 이모티콘 수, 클립보드에 복사된 이모티콘 수
    queue< pair<int, int> > q;
    q.push(make_pair(1, 0));

    checked[1][0] = true;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int cur = q.front().first;
            int copied = q.front().second;
            q.pop();

            if(cur == S)
                return;
            
            if(cur < S){
                // 1. 현재 이모티콘 복사
                if(!checked[cur][cur]){
                    checked[cur][cur] = true;
                    q.push(make_pair(cur, cur));
                }

                // 2. 이모티콘 붙여넣기
                if(!checked[cur + copied][copied]){
                    checked[cur + copied][copied] = true;
                    q.push(make_pair(cur + copied, copied));
                }
            }

            // 3. 이모티콘 1개 삭제
            if(cur > 0 && !checked[cur - 1][copied]){
                checked[cur - 1][copied] = true;
                q.push(make_pair(cur - 1, copied));
            }
        }
        result++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S;

    bfs();

    cout << result << '\n';
}