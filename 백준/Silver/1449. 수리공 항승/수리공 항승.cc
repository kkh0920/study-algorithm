#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L, arr[1000];

    cin >> N >> L;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int result = 1, prev = arr[0], l = 0;
    for(int i = 1; i < N; i++){
        l += arr[i] - prev;
        if(l >= L){
            l = 0;
            result++;
        }
        prev = arr[i];
    }

    cout << result << '\n';
}
