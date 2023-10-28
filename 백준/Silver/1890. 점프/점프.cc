#include <bits/stdc++.h>
using namespace std;

int N, arr[100][100];
long long visited[100][100];
int dx[2] = { 1, 0 }, dy[2] = { 0, 1 };

long long move(int curI, int curJ){
    if(curI == N - 1 && curJ == N - 1)
        return 1;
    if(arr[curI][curJ] == 0)
        return 0;

    for(int i = 0; i < 2; i++){
        int nI = curI + dx[i] * arr[curI][curJ];
        int nJ = curJ + dy[i] * arr[curI][curJ];
        if(nI >= N || nJ >= N)
            continue;
        if(visited[nI][nJ] > 0){
            visited[curI][curJ] += visited[nI][nJ];
            continue;
        }
        
        visited[curI][curJ] += move(nI, nJ);
    }

    return visited[curI][curJ];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    move(0, 0);

    cout << visited[0][0] << '\n';
}