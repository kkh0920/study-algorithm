#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue< pair<int, int> > pq;
    int N, result[1001] = { 0, };

    cin >> N;

    int d, w;
    for(int i = 0; i < N; i++){
        cin >> d >> w;
        pq.push(make_pair(w, d));
    }

    while(!pq.empty()){
        int day = pq.top().second;
        int score = pq.top().first;
        pq.pop();

        while(day > 0 && result[day] != 0){
            day--;
        }

        if(day != 0){
            result[day] = score;
        }
    }

    int maxScore = 0;
    for(int i = 1; i <= 1000; i++){
        maxScore += result[i];
    }

    cout << maxScore << '\n';
}