#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> box;
    int N, M, arr[50];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    cin >> M;

    int w;
    for(int i = 0; i < M; i++){
        cin >> w;
        box.push_back(w);
    }

    sort(arr, arr + N, compare);
    sort(box.begin(), box.end(), compare);

    if(arr[0] < box[0]){
        cout << -1 << '\n';
        return 0;
    }

    int result = 0;
    vector<int>::iterator iter = box.begin();
    while(!box.empty()){
        int idx = 0;
        while(idx < N && !box.empty()){
            iter = upper_bound(box.begin(), box.end(), arr[idx], greater<int>());
            if(iter == box.end()){
                if(*(iter - 1) <= arr[idx])
                    box.erase(iter - 1);
                else
                    break;
            }
            else if(iter != box.begin() && *(iter - 1) <= arr[idx])
                box.erase(iter - 1);
            else
                box.erase(iter);
            idx++;
        }
        result++;
    }
    
    cout << result << '\n';
}   
