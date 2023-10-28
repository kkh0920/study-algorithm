#include <bits/stdc++.h>
using namespace std;

int heap[100001], N, len = 0;

void UpHeap(int cur){
    if(cur == 1)
        return;
    int parent = cur / 2;
    if(heap[parent] > heap[cur]){
        swap(heap[parent], heap[cur]);
        UpHeap(parent);
    }
}

void DownHeap(int parent){
    int next = parent * 2;
    int nextNode = parent;
    if(next <= len && heap[next] < heap[parent])
        nextNode = next;
    if(next + 1 <= len && heap[next + 1] < heap[parent]){
        if(nextNode == parent || heap[nextNode] > heap[next + 1])
            nextNode = next + 1;
    }
    
    if(nextNode == parent)
        return;

    swap(heap[parent], heap[nextNode]);
    DownHeap(nextNode);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(num > 0){
            heap[++len] = num;
            UpHeap(len);
            continue;
        }
        if(len == 0){
            cout << 0 << '\n';
            continue;
        }
        cout << heap[1] << '\n';
        heap[1] = heap[len--];
        DownHeap(1);
    }
}