#include <bits/stdc++.h>
using namespace std;

//최대힙의 구현: 우선순위 큐 구현의 기반이 된다.
int heap[100001], N, len = 0;

//UpHeap "O(logN)"
//마지막 노드에 수를 삽입했을 때, 해당 노드와 부모 노드를 비교
//만약 '부모 노드'의 수가 '현재 노드'의 수 보다 작다면 swap
//해당 부모 노드를 재귀를 통해 '현재 노드'의 성질로 변환
//더이상 올라가지 못할때까지 반복
void UpHeap(int cur){
    if(cur == 1)
        return;
    int parent = cur / 2;
    if(heap[parent] < heap[cur]){
        swap(heap[parent], heap[cur]);
        UpHeap(parent);
    }
}

//DownHeap "O(logN)"
//루트 노드의 수(최댓값)을 pop
//가장 마지막에 삽입된 노드를 루트 노드에 삽입.
//해당 부모 노드와 자식 노드를 비교
//부모 노드보다 큰 자식 노드가 1개면 그대로 swap
//부모 노드보다 큰 자식 노드가 2개면, 자식 노드 중 더 큰 값과 swap
//'바뀐 자식 노드'를 재귀를 통해 '현재 노드'의 성질로 변환
//더이상 내려가지 못할때까지 반복
void DownHeap(int parent){
    //부모 노드의 자식 노드는 (N * 2, N * 2 + 1)
    int next = parent * 2;
    int nextNode = parent;
    if(next <= len && heap[next] > heap[parent])
        nextNode = next;
    if(next + 1 <= len && heap[next + 1] > heap[parent]){
        if(nextNode == parent || heap[nextNode] < heap[next + 1])
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
            for(int i = 1; i <= len; i++)
                cout << heap[i] << ' ';
            cout << '\n';
            continue;
        }
        if(len == 0){
            cout << 0 << '\n';
            continue;
        }
        cout << heap[1] << '\n';
        heap[1] = heap[len--];
        DownHeap(1);
        for(int i = 1; i <= len; i++)
            cout << heap[i] << ' ';
        cout << '\n';
    }
}