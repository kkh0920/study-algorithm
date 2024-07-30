#include <iostream>
#include <vector>
using namespace std;

int n, col = 1;
vector<int> bTree[10001], column[10001];
bool notRoot[10001];

void solution(int node, int level) {
    int left = bTree[node][0];
    int right = bTree[node][1];
    if(left != -1) {
        solution(left, level + 1);
    }
    column[level].push_back(col++);
    if(right != -1) {
        solution(right, level + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int p, lc, rc;
    for(int i = 0; i < n; i++) {
        cin >> p >> lc >> rc;
        bTree[p].push_back(lc);
        bTree[p].push_back(rc);
        if(lc != -1) notRoot[lc] = true;
        if(rc != -1) notRoot[rc] = true;
    }

    for(int i = 1; i <= n; i++) {
        if(!notRoot[i]) {
            solution(i, 1);
            break;
        }
    }

    int max = 0, level = 0;
    for(int i = 1; !column[i].empty(); i++) {
        int weight = column[i].back() - column[i].front() + 1;
        if(weight > max) {
            level = i;
            max = weight;
        }
    }

    cout << level << ' ' << max << '\n';

    return 0;
}