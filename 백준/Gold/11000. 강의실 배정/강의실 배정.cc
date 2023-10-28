#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pair<int, int> arr[200000];
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + N, compare);

    pq.push(make_pair(arr[0].second, arr[0].first));

    for(int i = 1; i < N; i++){
        if(pq.top().first <= arr[i].first)
            pq.pop();
        pq.push(make_pair(arr[i].second, arr[i].first));
    }

    cout << pq.size() << '\n';
}