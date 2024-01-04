#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, arr[125][125], cost[125][125];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void solve() {
    priority_queue< pair< int, pair<int, int> >, vector< pair<int, pair<int, int> > >, 
                        greater< pair<int, pair<int, int> > > > pq;
    pq.push(make_pair(arr[0][0], make_pair(0, 0)));
    cost[0][0] = arr[0][0];

    while(!pq.empty()) {
        int curCost = pq.top().first;
        int curI = pq.top().second.first;
        int curJ = pq.top().second.second;
        pq.pop();

        if(curCost > cost[curI][curJ])
            continue;
        
        for(int i = 0; i < 4; i++) {
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= N || nJ < 0 || nJ >= N) 
                continue;
            int nextCost = curCost + arr[nI][nJ];
            if(nextCost < cost[nI][nJ]) {
                cost[nI][nJ] = nextCost;
                pq.push(make_pair(nextCost, make_pair(nI, nJ)));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 1;
    while(1) {
        cin >> N;
        if(N == 0)
            break;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> arr[i][j];
                cost[i][j] = 123456789;
            }
        }

        solve();

        cout << "Problem "  << cnt++ << ": " << cost[N - 1][N - 1] << '\n';
    }

    return 0;
}