#include <bits/stdc++.h>
using namespace std;

pair<int, int> flower[100000];

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    
    cin >> N;

    int sm, sd, em, ed;
    for(int i = 0; i < N; i++){
        cin >> sm >> sd >> em >> ed;

        flower[i].first = sm * 100 + sd;
        flower[i].second = em * 100 + ed;
    }

    sort(flower, flower + N, compare);

    int endDay = 301, temp = 301, result = 0;
    for(int i = 0; i < N; i++){
        if(flower[i].first > endDay){
            if(flower[i].first > temp){
                result = 0;
                break;
            }
            endDay = temp;
            result++;
        }

        if(flower[i].second >= 1201){
            temp = 1201;
            result++;
            break;
        }

        temp = max(temp, flower[i].second);
    }
    
    if(temp < 1201)
        cout << 0 << '\n';
    else
        cout << result << '\n';
}   
