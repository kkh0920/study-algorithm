#include <bits/stdc++.h>
using namespace std;

long long arr[101] = { 0, 1, 1, 1, 2, 2, };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, m = 6;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;

        for(int j = m; j <= N; j++){
            arr[j] = arr[j - 1] + arr[j - 5];
        }
        m = N > m ? N : m;

        cout << arr[N] << '\n';
    }
}