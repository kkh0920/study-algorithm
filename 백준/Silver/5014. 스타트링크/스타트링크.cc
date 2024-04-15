#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d, result = 0;
bool visited[1000001];

void solve() {
    queue<int> q;
    q.push(s);

    visited[s] = true;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int cur = q.front();
            q.pop();

            if(cur == g)
                return;
            
            if(cur + u <= f && !visited[cur + u]) {
                visited[cur + u] = true;
                q.push(cur + u);
            }
            if(cur - d >= 1 && !visited[cur - d]) {
                visited[cur - d] = true;
                q.push(cur - d);
            }
        }
        result++;
    }
    result = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> f >> s >> g >> u >> d;

    solve();

    if(result == -1)
        cout << "use the stairs" << '\n';
    else
        cout << result << '\n'; 

    return 0;
}