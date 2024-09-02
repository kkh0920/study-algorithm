#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[21][21], num[5], result = 999999;
bool visited[21][21];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < 5; i++) {
        num[i] = 0;
    }
}

void calculate(int x, int y, int d1, int d2) {
    // 5번 선거구
    num[4] += arr[x][y];
    for(int i = x + 1; i < x + d1 + d2; i++) {
        int j = 1;
        while(!visited[i][j]) { j++; }
        
        num[4] += arr[i][j++];
        while(!visited[i][j]) {
            visited[i][j] = true;
            num[4] += arr[i][j++];
        }
        num[4] += arr[i][j];

        if(i == x + d1 + d2 - 1)
            num[4] += arr[i + 1][j - 1];
    }
    // 1번 선거구
    for(int i = 1; i < x + d1; i++) {
        for(int j = 1; j <= y; j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                num[0] += arr[i][j];
            }
        }
    }
    // 2번 선거구
    for(int i = 1; i <= x + d2; i++) {
        for(int j = y + 1; j <= N; j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                num[1] += arr[i][j];
            }
        }
    }
    // 3번 선거구
    for(int i = x + d1; i <= N; i++) {
        for(int j = 1; j < y - d1 + d2; j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                num[2] += arr[i][j];
            }
        }
    }
    // 4번 선거구
    for(int i = x + d2 + 1; i <= N; i++) {
        for(int j = y - d1 + d2; j <= N; j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                num[3] += arr[i][j];
            }
        }
    }

    sort(num, num + 5);
    result = min(result, num[4] - num[0]);
}

void divide(int x, int y, int d1, int d2) {
    for(int i = 0; i <= d1; i++) {
        visited[x + i][y - i] = true;
        visited[x + d2 + i][y + d2 - i] = true;
    }
    for(int i = 0; i <= d2; i++) {
        visited[x + i][y + i] = true;
        visited[x + d1 + i][y - d1 + i] = true;
    }
}

void selectXY(int d1, int d2) {
    for(int x = 1; x <= N; x++) {
        for(int y = 1; y <= N; y++) {
            if((x + d1 + d2 <= N) && (y + d2 <= N)) {
                init();
                divide(x, y, d1, d2);
                calculate(x, y, d1, d2);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int d1 = 1; d1 <= N; d1++) {
        for(int d2 = 1; d2 <= N; d2++) {
            selectXY(d1, d2);
        }
    }

    cout << result << '\n';

    return 0;
}