#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> result;
int capacity[3];
bool visited[201][201][201];

void pour(int& n1, int& n2, int idx2) {
    n2 += n1; n1 = 0;
    int over = n2 - capacity[idx2];
    if(over > 0) {
        n1 += over;
        n2 -= over;
    }
}

void bfs() {
    queue< pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(0, capacity[2])));
    visited[0][0][capacity[2]] = true;
    while(!q.empty()){
        int curA = q.front().first;
        int curB = q.front().second.first;
        int curC = q.front().second.second;
        q.pop();

        if(curA == 0) {
            result.push_back(curC);
        }
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == j) continue;
                int next[3] = { curA, curB, curC };
                pour(next[i], next[j], j);
                if(!visited[next[0]][next[1]][next[2]]) {
                    visited[next[0]][next[1]][next[2]] = true;
                    q.push(make_pair(next[0], make_pair(next[1], next[2])));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> capacity[0] >> capacity[1] >> capacity[2];

    bfs();

    sort(result.begin(), result.end());

    for(int x : result) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}