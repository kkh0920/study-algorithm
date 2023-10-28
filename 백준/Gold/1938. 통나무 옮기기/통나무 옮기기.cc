#include <bits/stdc++.h>
using namespace std;

queue< pair<int, pair<int, int> > > q;

vector< pair<int, int> > B, E;

int N, result = 0, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int sx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, sy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
char arr[50][51];
bool visited[2][50][50];

void bfs(){
    int spin = q.front().first;
    int si = q.front().second.first;
    int sj = q.front().second.second;

    visited[spin][si][sj] = true;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int curSpin = q.front().first;
            int curI = q.front().second.first;
            int curJ = q.front().second.second;
            q.pop();

            if(curSpin == (E[1].first - E[0].first) && curI == E[1].first && curJ == E[1].second)
                return;
            
            // Up, Down, Left, Right
            for(int j = 0; j < 4; j++){
                int nI = curI + dx[j];
                int nJ = curJ + dy[j];
                if(curSpin == 1){
                    if(nI <= 0 || nI >= N - 1 || nJ < 0 || nJ >= N)
                        continue;
                    if(arr[nI][nJ] == '1' || arr[nI - 1][nJ] == '1' || arr[nI + 1][nJ] == '1')
                        continue;
                }
                else{
                    if(nI < 0 || nI >= N || nJ <= 0 || nJ >= N - 1)
                        continue;
                    if(arr[nI][nJ] == '1' || arr[nI][nJ - 1] == '1' || arr[nI][nJ + 1] == '1')
                        continue;
                }
                if(visited[curSpin][nI][nJ])
                    continue;
                visited[curSpin][nI][nJ] = true;
                q.push(make_pair(curSpin, make_pair(nI, nJ)));
            }

            // Spin
            int nextSpin = curSpin == 1 ? 0 : 1;
            bool isPossible = true;
            if(visited[nextSpin][curI][curJ])
                continue;
            for(int j = 0; j < 8; j++){
                int nI = curI + sx[j];
                int nJ = curJ + sy[j];
                if(nI < 0 || nI >= N || nJ < 0 || nJ >= N || arr[nI][nJ] == '1'){
                    isPossible = false;
                    break;
                }
            }
            if(!isPossible)
                continue;
            visited[nextSpin][curI][curJ] = true;
            q.push(make_pair(nextSpin, make_pair(curI, curJ)));
        }
        result++;
    }
    result = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'B')
                B.push_back(make_pair(i, j));
            else if(arr[i][j] == 'E')
                E.push_back(make_pair(i, j));
        }
    }

    q.push(make_pair(B[1].first - B[0].first, make_pair(B[1].first, B[1].second)));

    bfs();

    cout << result << '\n';
}