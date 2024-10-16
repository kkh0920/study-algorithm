#include <iostream>
#include <queue>
using namespace std;

int target;
bool visited[1 << 9];

int dy[5] = { -3, 3 };

int toggle(int state, int pos) {
    int res = state ^ (1 << pos);
    // up, down
    if(pos + 3 <= 8) res ^= 1 << (pos + 3);
    if(pos - 3 >= 0) res ^= 1 << (pos - 3);
    // left, right
    if(pos + 1 <= 8 && pos / 3 == (pos + 1) / 3) res ^= 1 << (pos + 1);
    if(pos - 1 >= 0 && pos / 3 == (pos - 1) / 3) res ^= 1 << (pos - 1);
    return res;
}

int bfs() {
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int cur = q.front();
            q.pop();

            if(cur == target) {
                return time;
            }

            for(int i = 0; i < 9; i++) {
                int next = toggle(cur, i);
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
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

    int T;
    char c;

    cin >> T;

    while(T--) {
        target = 0;
        fill(visited, visited + (1 << 9), false);
        for(int i = 0; i < 9; i++) {
            cin >> c;
            if(c == '*') target += 1 << i;
        }
        cout << bfs() << '\n';
    }

    return 0;
}