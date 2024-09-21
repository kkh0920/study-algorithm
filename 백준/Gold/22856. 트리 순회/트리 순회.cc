#include <iostream>
#include <vector>
using namespace std;

int N, result = 0, visited = 0, lastNode;
vector<int> btree[100001];

void inorder(int node) {
    if(node == -1) return;
    inorder(btree[node][0]);
    if(++visited == N) lastNode = node;
    inorder(btree[node][1]);
}

void traversal(int node) { 
    if(btree[node][0] != -1) {
        result++;
        traversal(btree[node][0]);
        result++;
    }
    if(btree[node][1] != -1) {
        result++;
        traversal(btree[node][1]);
        result++;
    }
    if(node == lastNode) {
        cout << result << '\n';
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    cin >> N;

    int cur, left, right;
    for(int i = 0; i < N; i++) {
        cin >> cur >> left >> right;
        btree[cur].push_back(left);
        btree[cur].push_back(right);
    }

    inorder(1);
    traversal(1);

    return 0;
}