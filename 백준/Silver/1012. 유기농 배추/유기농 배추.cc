#include <iostream>
#include <queue>
using namespace std;

queue< pair<int, int> > q, temp;
int t, n, m, k, arr[50][50], x, y, result;
bool visited[50][50];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = 0;
            visited[i][j] = false;
        }
    }
    result = 0;
}

void bfs(){
    while(!temp.empty()){
        if(visited[temp.front().first][temp.front().second]){
            temp.pop();
            continue;
        }
        q.push(temp.front());
        visited[q.front().first][q.front().second] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                for(int j = 0; j < 4; j++){
                    int I = q.front().first + dx[j];
                    int J = q.front().second + dy[j];
                    if(I < 0 || J < 0 || I >= n || J >= m)
                        continue;
                    if(arr[I][J] == 1 && !visited[I][J]){
                        q.push(make_pair(I, J));
                        visited[I][J] = true;
                    }
                }
            }
            q.pop();
        }
        result++;
        temp.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> m >> n >> k;
        init();
        for(int j = 0; j < k; j++){
            cin >> y >> x;
            arr[x][y] = 1;
            temp.push(make_pair(x, y));
        }
        bfs();
        cout << result << '\n';
    }
}
