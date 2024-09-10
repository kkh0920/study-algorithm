#include <iostream>
#include <map>
#include <queue>
using namespace std;

map<int, bool> exist;
queue<int> q;
int N, K, dx[2] = { 1, -1 };
long long result = 0;

void solution() {
    int dist = 1;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int x = q.front();
            q.pop();

            for(int i = 0; i < 2; i++) {
                int nx = x + dx[i];
                if(exist.find(nx) != exist.end()) continue;
                
                result += dist;
                if(--K == 0) return;
                
                exist[nx] = true;
                q.push(nx);
            }
        }
        dist++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    int p;
    for(int i = 0; i < N; i++) {
        cin >> p;
        q.push(p);
        exist[p] = true;
    }

    solution();

    cout << result << '\n';

    return 0;
}