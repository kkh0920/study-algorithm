#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

long long s, t;
char op[4] = { '*', '+', '-', '/' };

set<long long> visited;

vector<int> result;

long long cal(long long num, char op) {
    if(op == '*') return num * num;
    if(op == '+') return num + num;
    if(op == '-') return 0;
    if(op == '/') return 1;
    return -1;
}

void bfs() {
    if(s == t) {
        cout << 0 << '\n';
        return;
    }

    queue< pair<long long, string> > q;
    q.push({s, ""});
    
    visited.insert(s);

    while(!q.empty()) {
        long long cur = q.front().first;
        string cur_op = q.front().second;
        q.pop();

        if(cur == t) {
            cout << cur_op << '\n';
            return;
        }

        for(int i = 0; i < 4; i++) {
            if(op[i] == '/' && cur == 0) continue;
            if(cur > t && (op[i] == '*' || op[i] == '+')) continue; 
        
            long long next = cal(cur, op[i]);
            if(visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push({next, cur_op + op[i]});
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;

    bfs();

    return 0;
}