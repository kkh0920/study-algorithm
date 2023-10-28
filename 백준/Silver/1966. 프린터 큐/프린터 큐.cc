#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue< pair<int, bool> > q;
    int c, n, m, num, arr[100];

    cin >> c;

    for(int i = 0; i < c; i++){
        cin >> n >> m;
        for(int j = 0; j < n; j++){
            cin >> num;
            arr[j] = num;
            if(j == m){
                q.push(make_pair(num, true));
                continue;
            }
            q.push(make_pair(num, false));
        }
        sort(arr, arr + n, compare);
        int cnt = 0;
        while(!q.empty()){
            if(arr[cnt] == q.front().first){
                cnt++;
                if(q.front().second){
                    cout << cnt << '\n';
                    break;
                }
                q.pop();
                continue;
            }
            q.push(q.front());
            q.pop();
        }
        while(!q.empty())
            q.pop();
    }
}