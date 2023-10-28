#include <bits/stdc++.h>
using namespace std;

int N, EWSN[4], cnt = 0;
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
bool visited[30][30];
double result = 1.0;

void dfs(double percent, int curI, int curJ){
    if(cnt == N){
        return;
    }

    for(int i = 0; i < 4; i++){
        double nP = percent * (EWSN[i] / 100.0);
        int nI = curI + dx[i];
        int nJ = curJ + dy[i];

        if(visited[nI][nJ]){
            result -= nP;
            continue;
        }
        
        cnt++;
        visited[nI][nJ] = true;

        dfs(nP, nI, nJ);

        cnt--;
        visited[nI][nJ] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < 4; i++){
        cin >> EWSN[i];
    }

    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            visited[i][j] = false;
        }
    }

    visited[15][15] = true;
    dfs(1, 15, 15);

    cout.precision(10);
    cout << result << '\n';
}