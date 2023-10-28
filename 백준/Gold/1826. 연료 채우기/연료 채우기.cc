#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;
    pair<int, int> arr[10000];
    int N, L, P;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    cin >> L >> P;

    sort(arr, arr + N, compare);

    int result = 0, prevDist = 0;
    for(int i = 0; i < N; i++){
        int dist = arr[i].first;
        int cost = arr[i].second;

        P -= dist - prevDist;

        if(pq.empty() && P < 0){
            result = -1;
            break;
        }

        while(!pq.empty() && P < 0){
            result++;
            P += pq.top();
            pq.pop();
        }

        if(P < 0){
            result = -1;
            break;
        }

        pq.push(cost);

        prevDist = dist;
    }

    if(result != -1){
        P -= L - prevDist;
        while(!pq.empty() && P < 0){
            result++;
            P += pq.top();
            pq.pop();
        }
    }

    cout << result << '\n';
}
