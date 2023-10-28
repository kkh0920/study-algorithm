#include <bits/stdc++.h>
using namespace std;

// 맨 왼쪽에 1 배치 -> n - 1 의 경우
// 맨 왼쪽에 00 배치 -> n - 2 의 경우

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, arr[1000001] = { 0, 1, 2, };

    cin >> N;

    for(int i = 3; i <= N; i++){
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    }

    cout << arr[N] << '\n';
}