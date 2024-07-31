#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int w, lw, n, q, l, arr[64][64], temp[64][64];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
bool visited[64][64];

void rotate(int x, int y, int width) {
    int k = x, l = y;
    for(int i = y + width - 1; i >= y; i--) {
        for(int j = x; j < x + width; j++) {
            temp[j][i] = arr[k][l++];
        }
        k++;
        l = y;
    }
    for(int i = x; i < x + width; i++) {
        for(int j = y; j < y + width; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void firestorm(int x, int y, int width) {
    if(width == lw) {
        rotate(x, y, width);
        return;
    }
    firestorm(x, y, width / 2);
    firestorm(x, y + (width / 2), width / 2);
    firestorm(x + (width / 2), y, width / 2);
    firestorm(x + (width / 2), y + (width / 2), width / 2);
}

void melt() {
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < w; j++) {
            temp[i][j] = arr[i][j];
            if(arr[i][j] == 0) {
                continue;
            }
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int nI = i + dx[k];
                int nJ = j + dy[k];
                if(nI < 0 || nI >= w || nJ < 0 || nJ >= w) {
                    continue;
                }
                if(arr[nI][nJ] == 0) {
                    continue;
                }
                cnt++;
            }
            if(cnt < 3) {
                temp[i][j]--;
            }
        }
    }
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < w; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

int getIce(int si, int sj) {
    queue< pair<int, int> > q;
    q.push(make_pair(si, sj));
    visited[si][sj] = true;

    int cnt = 1;
    while(!q.empty()) {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= w || nJ < 0 || nJ >= w) {
                continue;
            }
            if(visited[nI][nJ] || arr[nI][nJ] == 0) {
                continue;
            }
            cnt++;
            visited[nI][nJ] = true;
            q.push(make_pair(nI, nJ));
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    w = pow(2, n);
    
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < w; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < q; i++) {
        cin >> l;
        lw = pow(2, l);
        firestorm(0, 0, w);
        melt();
    }

    int sum = 0;
    int maxIce = 0;
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < w; j++) {
            sum += arr[i][j];
            if(!visited[i][j] && arr[i][j] > 0) {
                maxIce = max(maxIce, getIce(i, j));
            }
        }
    }

    cout << sum << '\n' << maxIce << '\n';

    return 0;
}