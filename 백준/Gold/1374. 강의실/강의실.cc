#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> arr[200000];
    int N;

    cin >> N;

    int idx, s, e, result = 0;
    for(int i = 0; i < N * 2; i+=2){
        cin >> idx >> s >> e;
        arr[i] = make_pair(s, 0); // 0은 시작 시간
        arr[i + 1] = make_pair(e, 1); // 1은 종료 시간
    }

    sort(arr, arr + (N * 2), compare);

    int num = 0;
    for(int i = 0; i < N * 2; i++){
        if(arr[i].second == 1)
            num--;
        else
            num++;
        result = num > result ? num : result;
    }

    cout << result << '\n';
}