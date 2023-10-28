#include <iostream>
#include <queue>
using namespace std;

queue< pair<int, int> > q;
int N, M, date = 0, cnt = 0, arr[1000][1000];

void infection(){
    while(q.size() != 0){
        int i = q.front().first;
        int j = q.front().second;
        int first, second;
        if(i > 0 && arr[i - 1][j] == 0){
            arr[i - 1][j] = 1;
            q.push(make_pair(i - 1, j));
        }
        if(i < N - 1 && arr[i + 1][j] == 0){
            arr[i + 1][j] = 1;
            q.push(make_pair(i + 1, j));
        }
        if(j > 0 && arr[i][j - 1] == 0){
            arr[i][j - 1] = 1;
            q.push(make_pair(i, j - 1));
        }
        if(j < M - 1 && arr[i][j + 1] == 0){
            arr[i][j + 1] = 1;
            q.push(make_pair(i, j + 1));
        }   
        q.pop();
        cnt--;
        if(cnt == 0){
            date++;
            cnt = q.size();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push(make_pair(i, j));
                cnt++;
            }
        }
    }

    infection();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == 0){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    
    cout << date - 1 << '\n';
}