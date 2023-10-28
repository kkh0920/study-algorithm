#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > maxGroup;
int arr[20][20], N, M, rainbowCnt = -1;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
bool visited[20][20];

void initVisited(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[i][j] = false;
        }
    }
}

void findMaxGroup(int si, int sj){
    vector< pair<int, int> > v, z;
    queue< pair<int, int> > q;

    v.push_back(make_pair(si, sj));
    q.push(make_pair(si, sj));

    visited[si][sj] = true;

    int color = arr[si][sj];
    int rc = 0;
    while(!q.empty()){
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nJ < 0 || nI >= N || nJ >= N)
                continue;
            if(nI <= si && nJ <= sj && arr[nI][nJ] != 0)
                continue;
            if(visited[nI][nJ] || arr[nI][nJ] < 0)
                continue;
            if(arr[nI][nJ] > 0 && arr[nI][nJ] != color)
                continue;
            
            if(arr[nI][nJ] == 0){
                z.push_back(make_pair(nI, nJ));
                rc++;
            }

            visited[nI][nJ] = true;
            
            v.push_back(make_pair(nI, nJ));
            q.push(make_pair(nI, nJ));
        }
    }

    if(v.size() == 1)
        return;
    
    for(int i = 0; i < z.size(); i++){
        visited[z[i].first][z[i].second] = false;
    }

    if(maxGroup.size() < v.size()){
        rainbowCnt = rc;
        maxGroup = v;
    }
    else if(maxGroup.size() == v.size() && rainbowCnt <= rc){
        rainbowCnt = rc;
        maxGroup = v;
    }
}

void removeGroup(){
    int size = maxGroup.size();
    for(int i = 0; i < size; i++){
        int ri = maxGroup[i].first;
        int rj = maxGroup[i].second;
        arr[ri][rj] = -2;
    }
}

void turn(){
    int temp[20][20];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp[N - 1 - j][i] = arr[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arr[i][j] = temp[i][j];
        }
    }
}

void down(){
    for(int i = N - 2; i >= 0; i--){
        for(int j = 0; j < N; j++){
            if(arr[i][j] < 0)
                continue;

            int curI = i;
            while(curI < N - 1 && arr[curI + 1][j] == -2){
                curI++;
            }

            if(curI != i){
                arr[curI][j] = arr[i][j];
                arr[i][j] = -2;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    int result = 0;
    while(1){
        initVisited();
        maxGroup.clear();
        rainbowCnt = -1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && arr[i][j] > 0)
                    findMaxGroup(i, j);
            }
        }

        if(maxGroup.empty())
            break;

        result += maxGroup.size() * maxGroup.size();

        removeGroup();
        down();
        turn();
        down();
    }

    cout << result << '\n';
}