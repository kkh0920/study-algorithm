#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

queue< pair<int, int> > cheese, blank, temp;
bool visited[101][101];
int N, M, arr[101][101], result = 0;
int di[4] = { -1, 1, 0, 0 }, dj[4] = { 0, 0, -1, 1}; 

void initVisited(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = false;
        }
    }
}

int dfs(){
    int bCount = 0;
    stack< pair<int, int> > s;
    while(!blank.empty()){
        s.push(blank.front());
        initVisited();
        while(!s.empty()){
            int cnt = 0;
            int I = s.top().first;
            int J = s.top().second;
            if(I == 0 || J == 0 || I >= N - 1 || J >= M - 1){
                bCount++;
                break;
            }
            visited[I][J] = true;
            for(int i = 0; i < 4; i++){
                if(visited[I + di[i]][J + dj[i]])
                    continue;
                if(arr[I + di[i]][J + dj[i]] == 0){ // I > 0 && J > 0 (가장자리는 공백)
                    s.push(make_pair(I + di[i], J + dj[i]));     
                    cnt++;
                    break;
                }
            }
            if(cnt == 0)
                s.pop();
        }
        while(!s.empty())
            s.pop();
        blank.pop();
        if(bCount == 2){
            while(!blank.empty())
                blank.pop();
        }
    }
    return bCount;
}

void bfs(){
    while(!cheese.empty()){
        while(!cheese.empty()){
            int cnt = 0;
            int I = cheese.front().first;
            int J = cheese.front().second;
            for(int i = 0; i < 4; i++){
                if(arr[I + di[i]][J + dj[i]] == 0){ // I > 0 && J > 0 (가장자리는 공백)
                    blank.push(make_pair(I + di[i], J + dj[i]));
                    cnt++;
                }
            }
            if(cnt >= 2 && dfs() == 2)
                temp.push(make_pair(I, J));
            while(!blank.empty())
                blank.pop();
            cheese.pop();
        }
        //cout << '\n';
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!temp.empty() && temp.front().first == i && temp.front().second == j){
                    arr[i][j] = 0;
                    temp.pop();
                }
                if(arr[i][j] == 1)
                    cheese.push(make_pair(i, j));
                //cout << arr[i][j] << ' ';
            }
            //cout << '\n';
        }
        //cout << '\n';
        result++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1)
                cheese.push(make_pair(i, j));
        }
    }

    bfs();

    cout << result << '\n';
}
