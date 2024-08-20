#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
char str[1001][31];
bool visited[1001];

vector<int> strIndex[1001];

bool isOneBetween(int idx1, int idx2) {
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        if(str[idx1][i] != str[idx2][i]) cnt++;
        if(cnt > 1) return false;
    }
    return cnt;
}

int bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    strIndex[0].push_back(start);
    int time = 1;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int cur = q.front(); q.pop();
            for(int next = 1; next <= n; next++) {
                if(!visited[next] && isOneBetween(cur, next)) {
                    visited[next] = true;
                    strIndex[time].push_back(next);
                    q.push(next);
                    if(next == end) 
                        return time;
                }
            }
        }
        time++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            cin >> str[i][j];
        }
    }

    int s, e;
    cin >> s >> e;

    int time = bfs(s, e);
    if(time == -1) {
        cout << time << '\n';
        return 0;
    }

    vector<int> result;

    int prevIndex = e;
    result.push_back(e);
    for(int t = time - 1; t >= 0; t--) {
        for(auto index : strIndex[t]) {
            if(isOneBetween(prevIndex, index)) {
                result.push_back(index);
                prevIndex = index;
                break;
            }
        }
    }

    for(vector<int>::iterator iter = result.end() - 1; iter >= result.begin(); iter--) {
        cout << *iter << ' ';
    }
    cout << '\n';

    return 0;
}