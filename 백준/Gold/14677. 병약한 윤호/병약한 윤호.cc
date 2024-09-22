#include <iostream>
#include <queue>
using namespace std;

int N;
char arr[1501], order[3] = { 'B', 'L', 'D' };
bool visited[1501][1501];

int bfs() {
    queue< pair<int, int> > q;
    q.push({0, 3 * N - 1});
    visited[0][3 * N - 1] = true;
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int front = q.front().first;
            int back = q.front().second;
            q.pop();

            if(front > back) {
                return time;
            }

            if(!visited[front + 1][back] && arr[front] == order[time % 3]) {
                visited[front + 1][back] = true;
                q.push({front + 1, back});
            }
            if(!visited[front][back - 1] && arr[back] == order[time % 3]) {
                visited[front][back - 1] = true;
                q.push({front, back - 1});
            }
        }
        time++;
    }
    return time - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N * 3; i++) {
        cin >> arr[i];
    }

    cout << bfs() << '\n';

    return 0;
}