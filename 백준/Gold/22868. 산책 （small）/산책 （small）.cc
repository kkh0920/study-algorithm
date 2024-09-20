#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[10001];
int N, M;
bool visited[10001];

void visit(int start, string str) {
    for(int i = 1; i <= N; i++) {
        visited[i] = false;
    }
    string num = "";
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ',') {
            visited[stoi(num)] = true;
            num = "";
        } else {
            num += str[i];
        }
    }
    visited[start] = false;
}

int bfs(int s, int e) {
    queue< pair<int, string> > q;
    q.push({s, to_string(s)});
    visited[s] = true;
    int move = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int cur = q.front().first;
            string path = q.front().second;
            q.pop();

            if(cur == e) {
                visit(s, path);
                return move;
            }

            for(auto next : graph[cur]) {
                if(!visited[next]) {
                    visited[next] = true;
                    q.push({next, path + "," + to_string(next)});
                }
            }
        }
        move++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    cin >> N >> M;

    int n1, n2;
    for(int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    int s, e;
    cin >> s >> e;

    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    cout << bfs(s, e) + bfs(e, s) << '\n';

    return 0;
}