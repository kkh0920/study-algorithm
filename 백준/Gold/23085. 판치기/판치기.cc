#include <iostream>
#include <queue>
using namespace std;

int N, K, head = 0, tail = 0, result = 0;
bool checked[3001];

void bfs(){
    queue< pair<int, int> > q;
    q.push(make_pair(head, tail));

    checked[head] = true;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int curHead = q.front().first;
            int curTail = q.front().second;
            q.pop();

            if(curHead == 0)
                return;

            int h = curHead <= K ? curHead : K;
            int t = K - h;
            while(t <= curTail && h >= 0){
                int nextHead = curHead - h + t;
                int nextTail = curTail + h - t;
                if(!checked[nextHead]){
                    checked[nextHead] = true;
                    q.push(make_pair(nextHead, nextTail));
                }
                h--;
                t++;
            }
        }
        result++;
    }
    result = -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    char c;
    for(int i = 0; i < N; i++){
        cin >> c;
        if(c == 'H') head++;
        else tail++;
    }

    bfs();

    cout << result << '\n';

}