#include <bits/stdc++.h>
using namespace std; 

class Node{
public:
    int a, b, c;
    Node(int s, int d, int w){
        a = s; b = d; c = w;
    }
};

struct compare{
    bool operator()(Node a, Node b){
        return a.c > b.c;
    }
};

priority_queue< Node, vector<Node>, compare > pq;
int parent[10001], result = 0;

int findRoot(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = findRoot(parent[x]);
}

void unionRoot(int x, int y){
    int rx = findRoot(x);
    int ry = findRoot(y);

    if(rx != ry)
        parent[ry] = rx;
}

void kruskal(){
    while(!pq.empty()){
        int node1 = pq.top().a;
        int node2 = pq.top().b;
        int weight = pq.top().c;
        pq.pop();

        if(findRoot(node1) == findRoot(node2))
            continue;
        
        unionRoot(node1, node2);

        result += weight;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;

    cin >> v >> e;

    int s, d, w;
    for(int i = 0; i < e; i++){
        cin >> s >> d >> w;
        pq.push(Node(s, d, w));
    }

    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }

    kruskal();

    cout << result << '\n';
}