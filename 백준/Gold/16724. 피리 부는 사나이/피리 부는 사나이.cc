#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, result = 0;
char arr[1000][1000];
bool visited[1000][1000], checked[1000][1000];

// 지도 밖으로 나가는 방향의 입력은 주어지지 않는다.

pair<int, int> nextPoint(int i, int j) {
    switch (arr[i][j]) {
        case 'U':
            return make_pair(i - 1, j);
        case 'D':
            return make_pair(i + 1, j);
        case 'L':
            return make_pair(i, j - 1);
        case 'R':
            return make_pair(i, j + 1);   
    }
}

void solution(int si, int sj) {
    int curI = si;
    int curJ = sj;
    int nextI, nextJ;
    vector< pair<int, int> > check;

    visited[curI][curJ] = true;
    check.push_back(make_pair(curI, curJ));
    while(1) {
        pair<int, int> np = nextPoint(curI, curJ);
        nextI = np.first;
        nextJ = np.second;

        if(checked[nextI][nextJ])
            break;
        if(visited[nextI][nextJ]) {
            result++;
            break;
        }

        visited[nextI][nextJ] = true;
        check.push_back(make_pair(nextI, nextJ));
        curI = nextI;
        curJ = nextJ;
    }
    
    for(int i = 0; i < check.size(); i++) {
        checked[check[i].first][check[i].second] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!checked[i][j]) {
                solution(i, j);
            }
        }
    }
    
    cout << result << '\n';

    return 0;
}