#include <bits/stdc++.h>
using namespace std;

int parent[200000];

int findRoot(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = findRoot(parent[x]);
}

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, result = 0;
    pair<int, int> arr[200000];

    cin >> N;

    int dl, cr;
    for(int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
        parent[i] = i;
    }
    parent[N] = N;

    sort(arr, arr + N, compare);

    for(int i = 0; i < N; i++){
        int deadline = arr[i].first;
        int cupNoodle = arr[i].second;

        int root = findRoot(deadline);
        if(root == 0)
            continue;

        result += cupNoodle;

        parent[root] = findRoot(root - 1);
    }

    cout << result << '\n';
}   
