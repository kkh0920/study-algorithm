#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, T;
map<pair<int, int>, bool> visited;

int bfs() {
    queue< pair<int, int> > q;
    q.push(make_pair(0, 0));
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            
            if(curY == T) return time;
            
            for(int offsetX = -2; offsetX <= 2; offsetX++) {
                for(int offsetY = -2; offsetY <= 2; offsetY++) {
                    int nX = curX + offsetX;
                    int nY = curY + offsetY;
                    if(visited.find(make_pair(nX, nY)) == visited.end())
                        continue;
                    if(visited[make_pair(nX, nY)] == false) {
                        visited[make_pair(nX, nY)] = true;
                        q.push(make_pair(nX, nY));
                    }
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

    cin >> n >> T;

    int x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        visited[make_pair(x, y)] = false;
    }

    cout << bfs() << '\n';

    return 0;
}