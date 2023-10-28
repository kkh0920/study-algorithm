#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue< pair<int, int> > pq;

    multiset<int> ms;
    int N, K;
    long long result = 0;

    cin >> N >> K;

    int M, V;
    for(int i = 0; i < N; i++){
        cin >> M >> V;
        pq.push(make_pair(V, M));
    }
    
    int C;
    for(int i = 0; i < K; i++){
        cin >> C;
        ms.insert(C);
    }

    while(!pq.empty() && !ms.empty()){
        if(*(--ms.end()) >= pq.top().second){
            ms.erase(ms.lower_bound(pq.top().second));
            result += pq.top().first;
        }
        pq.pop();
    }

    cout << result << '\n';

}