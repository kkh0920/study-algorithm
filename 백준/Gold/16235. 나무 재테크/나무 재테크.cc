#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector< pair<int, pair<int, int> > > dead, tree, tempTree;

int N, M, K, map[100][100], A[100][100];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void spring() {
    for(int i = 0; i < tree.size(); i++) {
        int age = tree[i].first;
        int x = tree[i].second.first;
        int y = tree[i].second.second;
        if(map[x][y] < age) {
            dead.push_back({age, {x, y}});
            continue;
        }
        map[x][y] -= age;
        tree[i].first++;
        tempTree.push_back(tree[i]);
    }
    tree.clear();
}

void summer() {
    for(int i = 0; i < dead.size(); i++) {
        map[dead[i].second.first][dead[i].second.second] += dead[i].first / 2;
    }
    dead.clear();
}

void fall() {
    for(int i = 0; i < tempTree.size(); i++) {
        int age = tempTree[i].first;
        int x = tempTree[i].second.first;
        int y = tempTree[i].second.second;
        if(age % 5 != 0) {
            continue;
        }
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }
            tree.push_back({1, {nx, ny}});
        }
    }
    for(int i = 0; i < tempTree.size(); i++) {
        tree.push_back(tempTree[i]);
    }
    tempTree.clear();
}

void winter() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            map[i][j] += A[i][j];
        }
    }
}

void simulation() {
    sort(tree.begin(), tree.end());
    while(K--) {
        spring();
        summer();
        fall();
        winter();
    }
    cout << tree.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
            map[i][j] = 5;
        }
    }

    int x, y, z;
    for(int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        tree.push_back({z, {x - 1, y - 1}});
    }

    simulation();

    return 0;
}