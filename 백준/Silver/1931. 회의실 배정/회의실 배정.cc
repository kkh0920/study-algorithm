#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector< pair<int, int> > v;
 
    cin >> n;

    int s, e;
    for(int i = 0; i < n; i++){
        cin >> s >> e;
        v.push_back(make_pair(s, e));
    }

    sort(v.begin(), v.end(), compare);

    int temp = v[0].second;
    int result = 1;
    for(int i = 1; i < n; i++){
        if(v[i].first >= temp){
            temp = v[i].second;
            result++;
        }
    }

    cout << result << '\n';
}