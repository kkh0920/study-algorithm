#include <bits/stdc++.h>
using namespace std;

int N, M, arr[101][101], result = 0;
int si, sj, sd, ei, ej, ed;
pair<int, int> m[4] = { make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0) };
pair<int, int> dir[4] = { make_pair(4, 3), make_pair(3, 4), make_pair(1, 2), make_pair(2, 1) };
bool visited[101][101][5];

void bfs(){
    queue< pair< pair<int, int>, int > > q;
    q.push(make_pair(make_pair(si, sj), sd));

    visited[si][sj][sd] = true;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int curI = q.front().first.first;
            int curJ = q.front().first.second;
            int curDir = q.front().second;
            q.pop();

            if(curI == ei && curJ == ej && curDir == ed)
                return;
            
            // Move 1, 2, 3
            int nI = curI, nJ = curJ;
            for(int j = 0; j < 3; j++){
                nI += m[curDir - 1].first;
                nJ += m[curDir - 1].second;
                if(nI <= 0 || nI > N || nJ <= 0 || nJ > M || arr[nI][nJ] == 1)
                    break;
                if(visited[nI][nJ][curDir])
                    continue;
                visited[nI][nJ][curDir] = true;
                q.push(make_pair(make_pair(nI, nJ), curDir));
            }

            // Turn left, right
            int leftDir = dir[curDir - 1].first;
            int rightDir = dir[curDir - 1].second;
            if(!visited[curI][curJ][leftDir]){
                visited[curI][curJ][leftDir] = true;
                q.push(make_pair(make_pair(curI, curJ), leftDir));
            }
            if(!visited[curI][curJ][rightDir]){
                visited[curI][curJ][rightDir] = true;
                q.push(make_pair(make_pair(curI, curJ), rightDir));
            }
        }
        result++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
        }
    }
    
    cin >> si >> sj >> sd;
    cin >> ei >> ej >> ed;

    bfs();

    cout << result << '\n';
}   