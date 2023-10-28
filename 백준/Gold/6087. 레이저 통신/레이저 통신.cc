#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class State{
public:
    int i, j, mirrorCnt, dir;
    State(int I, int J, int mc, int d){
        i = I; j = J; mirrorCnt = mc; dir = d;
    }
};

vector< pair<int, int> > c;
int N, M, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char arr[100][101];
int visited[100][100][4];

void bfs(){
    queue<State> q;
    
    for(int i = 0; i < 4; i++){
        visited[c[0].first][c[0].second][i] = 0;

        int nI = c[0].first + dx[i];
        int nJ = c[0].second + dy[i];
        int nDir = i;
        if(nI < 0 || nI >= N || nJ < 0 || nJ >= M || arr[nI][nJ] == '*')
            continue;
        visited[nI][nJ][nDir] = 0;
        q.push(State(nI, nJ, 0, nDir));
    }
    
    while(!q.empty()){
        int curI = q.front().i;
        int curJ = q.front().j;
        int mirrorCnt = q.front().mirrorCnt;
        int curDir = q.front().dir;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nDir = i;
            if((curDir == 0 && nDir == 1) || (curDir == 1 && nDir == 0))
                continue;
            if((curDir == 2 && nDir == 3) || (curDir == 3 && nDir == 2))
                continue;
            
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            int nCnt = curDir != nDir ? mirrorCnt + 1 : mirrorCnt;
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= M || arr[nI][nJ] == '*')
                continue;
            if(visited[nI][nJ][nDir] <= nCnt)
                continue;
    
            visited[nI][nJ][nDir] = nCnt;
            q.push(State(nI, nJ, nCnt, nDir));
        }
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'C')
                c.push_back(make_pair(i, j));

            for(int k = 0; k < 4; k++){
                visited[i][j][k] = 10000;
            }
        }
    }

    bfs();

    int result = 10000;
    for(int i = 0; i < 4; i++){
        result = min(result, visited[c[1].first][c[1].second][i]);
    }

    cout << result << '\n';
}