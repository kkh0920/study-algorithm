#include <bits/stdc++.h>
using namespace std;

queue< pair<int, int > > w, s;
int result = 0, R, C, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[50][51];

void bfs(){
    while(!s.empty()){
        result++;
        int sizeS = s.size();
        for(int i = 0; i < sizeS; i++){
            int curSI = s.front().first;
            int curSJ = s.front().second;  
            s.pop();

            if(arr[curSI][curSJ] == '*')
                continue;

            for(int i = 0; i < 4; i++){
                int nI = curSI + dx[i];
                int nJ = curSJ + dy[i];
                if(nI < 0 || nI >= R || nJ < 0 || nJ >= C)
                    continue;
                if(arr[nI][nJ] == 'S' || arr[nI][nJ] == '*' || arr[nI][nJ] == 'X')
                    continue;
                if(arr[nI][nJ] == 'D')
                    return;
                arr[nI][nJ] = 'S';
                s.push(make_pair(nI, nJ));
            }
        }
        int sizeW = w.size();
        for(int i = 0; i < sizeW; i++){
            int curWI = w.front().first;
            int curWJ = w.front().second;  
            w.pop();

            for(int i = 0; i < 4; i++){
                int nI = curWI + dx[i];
                int nJ = curWJ + dy[i];
                if(nI < 0 || nI >= R || nJ < 0 || nJ >= C)
                    continue;
                if(arr[nI][nJ] == '*' || arr[nI][nJ] == 'D' || arr[nI][nJ] == 'X')
                    continue;
                arr[nI][nJ] = '*';
                w.push(make_pair(nI, nJ));
            }
        }
    }
    result = -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '*')
                w.push(make_pair(i, j));
            if(arr[i][j] == 'S')
                s.push(make_pair(i, j));
        }
    }

    bfs();

    if(result == -1)
        cout << "KAKTUS\n";
    else
        cout << result << '\n';
}