#include <bits/stdc++.h>
using namespace std;

int parent[100001];

int findRoot(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = findRoot(parent[x]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G, P;

    cin >> G >> P;

    for(int i = 0; i <= G; i++){
        parent[i] = i;
    }

    int g;
    for(int i = 0; i < P; i++){
        cin >> g;

        int root = findRoot(g);

        if(root == 0){
            cout << i << '\n';
            return 0;
        }

        parent[root] = findRoot(root - 1);
    }

    cout << P << '\n';
}