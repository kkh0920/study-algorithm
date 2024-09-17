#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool graph[100][100], rgraph[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int n1, n2;
    for(int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        graph[n1][n2] = true;
        rgraph[n2][n1] = true;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                if(graph[j][i] && graph[i][k]) {
                    graph[j][k] = true;
                }
                if(rgraph[j][i] && rgraph[i][k]) {
                    rgraph[j][k] = true;
                }
            }
        }
    }

    int result = 0;
    for(int i = 1; i <= N; i++) {
        int cnt = 1, rcnt = 1;
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;
            if(graph[i][j]) cnt++;
            if(rgraph[i][j]) rcnt++;
        }
        if(cnt > (N + 1) / 2 || rcnt > (N + 1) / 2) {
            result++;
        }
    }

    cout << result << '\n';

    return 0;
}