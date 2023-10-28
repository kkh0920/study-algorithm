#include <bits/stdc++.h>
using namespace std;

int N, M, result = 0;
char cur[50][51], res[50][51];

void change(int si, int sj){
    for(int i = si; i < si + 3; i++){
        for(int j = sj; j < sj + 3; j++){
            cur[i][j] = cur[i][j] == '1' ? '0' : '1';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> cur[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> res[i][j];
        }
    }

    for(int i = 0; i < N - 2; i++){
        for(int j = 0; j < M - 2; j++){
            if(cur[i][j] != res[i][j]){
                change(i, j);
                result++;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(cur[i][j] != res[i][j]){
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << result << '\n';
}   
