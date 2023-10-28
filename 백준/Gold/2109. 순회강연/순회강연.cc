#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue< pair<int, int> > pq;
    int N, arr[10001] = { 0 };

    cin >> N;

    int p, d;
    for(int i = 0; i < N; i++){
        cin >> p >> d;
        pq.push(make_pair(p, d));
    }

    while(!pq.empty()){
        int cost = pq.top().first;
        int day = pq.top().second;
        pq.pop();

        while(day > 0 && arr[day] != 0){
            day--;
        }
        
        arr[day] = cost;
    }

    int result = 0;
    for(int i = 1; i <= 10000; i++){
        result += arr[i];
    }

    cout << result << '\n';
}