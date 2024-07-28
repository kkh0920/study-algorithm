#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> result;
int M, N, K;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
bool filled[100][100], visited[100][100];

void bfs(int si, int sj) {
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));
    visited[si][sj] = true;
    int size = 1;
    while(!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= M || nJ < 0 || nJ >= N)
                continue;
            if(visited[nI][nJ] || filled[nI][nJ])
                continue;
            size++;
            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }
    result.push_back(size);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> K;

    int x1, y1, x2, y2;
    for(int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j < x2; j++) {
            for(int k = y1; k < y2; k++) {
                filled[k][j] = true;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j] && !filled[i][j]) {
                bfs(i, j);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for(int x : result) {
        cout << x << ' ';
    }
    cout << '\n';
}