#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;
    int N, K, arr[10000];

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for(int i = 1; i < N; i++){
        pq.push(arr[i] - arr[i - 1]);
    }

    while(--K && !pq.empty()){
        pq.pop();
    }

    int result = 0;
    while(!pq.empty()){
        result += pq.top();
        pq.pop();
    }

    cout << result << '\n';
}