#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< pair<int, int> > virus;
queue< pair<int, int> > q;
int n, m, origin[50][50], map[50][50], result = 99999;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            map[i][j] = origin[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        q.push(virus[i]);
        map[virus[i].first][virus[i].second] = 3;
    }
}

int infection() {
    init();
    int time = -1;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int curI = q.front().first;
            int curJ = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nI = curI + dx[i];
                int nJ = curJ + dy[i];
                if(nI < 0 || nI >= n || nJ < 0 || nJ >= n)
                    continue;
                if(map[nI][nJ] == 1 || map[nI][nJ] == 3)
                    continue;
                map[nI][nJ] = 3;
                q.push(make_pair(nI, nJ));
            }
        }
        time++;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 0 || map[i][j] == 2) {
                return 99999;
            }
        }
    }

    return time;
}

void placeVirus(int idx, int cnt) {
    if(cnt == 0) {
        result = min(result, infection());
        return;
    }
    int index = idx;
    while(index < n * n) {
        int i = index / n;
        int j = index % n;
        if(origin[i][j] == 2) {
            virus.push_back(make_pair(i, j));
            placeVirus(index + 1, cnt - 1);
            virus.pop_back();
        }
        index++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> origin[i][j];
        }
    }

    placeVirus(0, m);

    cout << (result == 99999 ? -1 : result) << '\n';

    return 0;
}