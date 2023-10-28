#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int> > pq;
    int n, result = 0;

    cin >> n;

    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        pq.push(num);
    }

    while(pq.size() > 1){
        int temp = pq.top();
        pq.pop();
        temp += pq.top();
        pq.pop();

        result += temp;

        pq.push(temp);
    }

    cout << result << '\n';
}