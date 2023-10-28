#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue< long long, vector<long long>, greater<long long> > pq;
    int T, K, num;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> K;
        for(int j = 0; j < K; j++){
            cin >> num;
            pq.push(num);
        }

        long long result = 0;
        while(pq.size() > 1){
            long long temp = 0;
            for(int i = 0; i < 2; i++){
                temp += pq.top();
                pq.pop();
            }
            result += temp;
            pq.push(temp);
        }
        pq.pop();

        cout << result << '\n';
    }
}  