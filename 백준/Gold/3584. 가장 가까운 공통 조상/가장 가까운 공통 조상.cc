#include <iostream>
#include <vector>
using namespace std;

int t, n;
bool visited[10001];
vector<int> reverseTree[10001], vNode;

void init() {
    for(int i = 1; i <= n; i++) {
        reverseTree[i].clear();
    }
    for(int i = 0; i < vNode.size(); i++) {
        visited[vNode[i]] = false;
    }
    vNode.clear();
}

void visit(int node) {
    visited[node] = true;
    vNode.push_back(node);
}

int solution(int node1, int node2) {
    int cursor = node1;
    visit(node1);
    while(!reverseTree[cursor].empty()) {
        cursor = reverseTree[cursor][0];
        visit(cursor);
    }

    cursor = node2;
    while(!visited[cursor]) {
        cursor = reverseTree[cursor][0];
    }
    return cursor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    int p, c, n1, n2;
    for(int i = 0; i < t; i++) {
        init();
        cin >> n;
        for(int j = 0; j < n - 1; j++) {
            cin >> p >> c;
            reverseTree[c].push_back(p);
        }
        cin >> n1 >> n2;
        cout << solution(n1, n2) << '\n';
    }
    
    return 0;
}