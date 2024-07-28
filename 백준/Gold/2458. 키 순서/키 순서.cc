#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, result = 0;
bool visited[501];
vector<int> graph[501], reverseGraph[501];

void initVisited() {
    for(int i = 1; i <= N; i++) {
        visited[i] = false;
    }
}

int findUpper(int student) {
    queue<int> q;
    q.push(student);
    int upper = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        int size = graph[cur].size();
        for(int i = 0; i < size; i++) {
            int next = graph[cur][i];
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                upper++;
            }
        }
    }
    return upper;
}

int findLower(int student) {
    queue<int> q;
    q.push(student);
    int lower = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        int size = reverseGraph[cur].size();
        for(int i = 0; i < size; i++) {
            int next = reverseGraph[cur][i];
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                lower++;
            }
        }
    }
    return lower;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int n1, n2;
    for(int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        reverseGraph[n2].push_back(n1);
    }

    for(int i = 1; i <= N; i++) {
        initVisited();
        if(findUpper(i) + findLower(i) == N - 1) {
            result++;
        }
    }

    cout << result << '\n';

    return 0;
}