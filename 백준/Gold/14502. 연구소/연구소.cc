#include <iostream>
#include <queue>
using namespace std;

queue< pair<int, int> > q, qc;
int N, M, origin[8][8], temp[8][8], result = 0;

void initTemp(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            temp[i][j] = origin[i][j];
        }
    }
}

void initQueue(){
    int size = qc.size();
    for(int i = 0; i < size; i++){
        q.push(qc.front());
        qc.push(qc.front());
        qc.pop();
    }
}

void bfs(){
    int i, j;
    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        if(i > 0 && temp[i - 1][j] == 0){
            temp[i - 1][j] = 2;
            q.push(make_pair(i - 1, j));
        }
        if(i < N - 1 && temp[i + 1][j] == 0){
            temp[i + 1][j] = 2;
            q.push(make_pair(i + 1, j));
        }
        if(j > 0 && temp[i][j - 1] == 0){
            temp[i][j - 1] = 2;
            q.push(make_pair(i, j - 1));
        }
        if(j < M - 1 && temp[i][j + 1] == 0){
            temp[i][j + 1] = 2;
            q.push(make_pair(i, j + 1));
        }
        q.pop();
    }

    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(temp[i][j] == 0)
                count++;
        }
    }

    result = count > result ? count : result;

    initTemp();
    initQueue();
}

void makeWall(int count){
    if(count == 3){
        bfs();
        return;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(temp[i][j] == 0){
                temp[i][j] = 1;
                origin[i][j] = 1;

                makeWall(count + 1);

                temp[i][j] = 0;
                origin[i][j] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> origin[i][j];
            temp[i][j] = origin[i][j];
            if(origin[i][j] == 2){
                q.push(make_pair(i, j));
                qc.push(make_pair(i, j));
            }
        }
    }
    
    makeWall(0);
    
    cout << result << '\n';
}