#include <iostream>
using namespace std;

int N, M, arr[101][101];

void init(int n){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = 123456789;
        }
    }
}

void input() {
    int s, e;
    for(int i = 0; i < M; i++) {
        cin >> s >> e;
        arr[s][e] = 1;
        arr[e][s] = 1;
    }
}

void solve() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    int result = 0, minCnt = 123456789;

    for(int i = 1; i <= N; i++) {
        int sum = 0;
        for(int j = 1; j <= N; j++) {
            sum += arr[i][j];
        }
        if(sum < minCnt) {
            result = i;
            minCnt = sum;
        }
    }

    cout << result << '\n';
}

int main(){
    cin >> N >> M;
    
    init(N);

    input();
    
    solve();

    return 0;
}