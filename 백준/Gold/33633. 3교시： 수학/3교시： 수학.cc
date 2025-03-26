#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
queue<long long> q;
vector<long long> v;

void bfs() {
    q.push(1);
    while(--N && !q.empty()) {
        long long size = q.size();
        while(size--) {
            long long num = q.front(); q.pop();
            q.push(num * 2);
            if((num - 1) % 3 == 0 && ((num - 1) / 3) % 2 == 1 && (num - 1) / 3 != 1) {
                q.push((num - 1) / 3);
            }
        }
    }
    cout << q.size() << '\n';
    while(!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }
    sort(v.begin(), v.end());
    for(long long num : v) {
        cout << num << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    bfs();

    return 0;
}