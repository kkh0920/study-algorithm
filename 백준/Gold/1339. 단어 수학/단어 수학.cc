#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue< pair<int, int> > pq;
    int N, num = 9, weight[26] = { 0, }, result = 0;
    string str[10];

    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> str[i];

        int len = str[i].length();
        for(int j = 0; j < str[i].length(); j++){
            weight[str[i][j] - 'A'] += pow(10, --len);
        }
    }

    for(int i = 0; i < 26; i++){
        if(weight[i] != 0)
            pq.push(make_pair(weight[i], i));
    }

    while(!pq.empty()){
        result += weight[pq.top().second] * num--;
        pq.pop();
    }

    cout << result << '\n';
}