#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<int, int> person[50]; 
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> person[i].first >> person[i].second;
    }

    for(int i = 0; i < n; i++){
        int rank = 1;
        int p1W = person[i].first, p1H = person[i].second;
        for(int j = 0; j < n; j++){
            int p2W = person[j].first, p2H = person[j].second;
            if(p1W < p2W && p1H < p2H)
                rank++;
        }
        cout << rank << ' ';   
    }
    cout << '\n';
}