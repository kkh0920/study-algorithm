#include <iostream>
using namespace std;

int N, M, H;
bool ladder[31][11][11], origin[31][11][11];

bool simulation() {
    for(int i = 1; i <= N; i++) {
        int x = i, height = 1;
        while(height <= H) {
            if(x > 1 && ladder[height][x - 1][x]) {
                x--;
            } else if(x < N && ladder[height][x][x + 1]) {
                x++;
            }
            height++;
        }
        if(i != x) return false;
    }
    return true;
}

bool place(int nextI, int nextJ, int cnt) {
    if(cnt == 0) {
        return simulation();
    }
    int j = nextJ;
    for(int i = nextI; i <= H; i++) {
        for(; j <= N - 1; j++) {
            if(j > 1 && ladder[i][j - 1][j]) continue;
            if(j < N - 1 && ladder[i][j + 1][j + 2]) continue;
            
            if(!ladder[i][j][j + 1]) {
                ladder[i][j][j + 1] = true;
                
                bool isPossible = false;
                if(j == N - 1) {
                    isPossible = place(i + 1, 1, cnt - 1);
                } else {
                    isPossible = place(i, j + 1, cnt - 1);
                }
                if(isPossible) return true;
                
                ladder[i][j][j + 1] = false;
            }
        }
        j = 1;
    }
    return false;
}

void initLadder() {
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= N - 1; j++) {
            ladder[i][j][j + 1] = origin[i][j][j + 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> H;

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        origin[a][b][b + 1] = true;
    }

    int result = -1;
    for(int i = 0; i <= 3; i++) {
        initLadder();
        if(place(1, 1, i)) {
            result = i;
            break;
        }
    }

    cout << result << '\n';

    return 0;
}