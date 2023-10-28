#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[12][7];
bool visited[12][6];

void initVisited(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            visited[i][j] = false;
        }
    }
}

bool isRemovable(int si, int sj){
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));
    
    initVisited();
    visited[si][sj] = true;

    int cnt = 1;
    char color = arr[si][sj];
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= 12 || nJ < 0 || nJ >= 6)
                continue;
            if(visited[nI][nJ] || arr[nI][nJ] != color)
                continue;
            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
            cnt++;
        }
    }
    if(cnt >= 4){
        return true;
    }
    return false;
}

void remove(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            if(visited[i][j])
                arr[i][j] = '.';
        }
    }
}

void drop(){
    for(int i = 0; i < 6; i++){
        int idx = 0;
        while(idx < 12 && arr[11 - idx][i] != '.'){
            idx++;
        }
        int temp = idx;
        for(int j = (11 - temp) - 1; j >= 0; j--){
            if(arr[j][i] != '.'){
                arr[11 - idx++][i] = arr[j][i];
                arr[j][i] = '.';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cin >> arr[i][j];
        }
    }

    int result = 0;
    bool isRemoved;
    while(1){
        isRemoved = false;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(arr[i][j] != '.' && !visited[i][j]){
                    if(isRemovable(i, j)){
                        remove();
                        isRemoved = true;
                    }
                }
            }
        }
        if(!isRemoved)
            break;
        drop();
        result++;
    }

    cout << result << '\n';
}