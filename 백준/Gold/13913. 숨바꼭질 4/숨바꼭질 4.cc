#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
vector<int> result;
int visited[200001], n, k;

void trace() {
    int node = k;
    result.push_back(node);
    while(visited[node] > 1) {
        int t = visited[node] - 1;
        if(node - 1 >= 0 && visited[node - 1] == t) {
            node -= 1;
        } else if(visited[node + 1] == t) {
            node += 1;
        } else if(node % 2 == 0 && visited[node / 2] == t) {
            node /= 2;
        }
        result.push_back(node);
    }
}

void bfs() {
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while(!q.empty()) {
        int cur = q.front(); 
        q.pop();
        if(cur == k) {
            break;
        }
        if(cur + 1 <= 100000 && visited[cur + 1] == 0) {
            q.push(cur + 1);
            visited[cur + 1] = visited[cur] + 1;
        }
        if(cur - 1 >= 0 && visited[cur - 1] == 0) {
            q.push(cur - 1);
            visited[cur - 1] = visited[cur] + 1;
        }
        if(cur * 2 <= 200000 && visited[cur * 2] == 0) {
            q.push(cur * 2);
            visited[cur * 2] = visited[cur] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    bfs();
    trace();

    cout << visited[k] - 1 << '\n';
    for(auto iter = result.rbegin(); iter != result.rend(); iter++) {
        cout << *iter << ' ';
    }
    cout << '\n';

    return 0;
}