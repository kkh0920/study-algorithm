#include <bits/stdc++.h>
using namespace std;

//Singly Linked List를 기반으로 하는 Priority Queue
class ListBasedPriorityQueue{
private:
    class Node{
    public:
        int data;
        Node* next;
        Node(int d){ data = d; }
    };
    Node* head;
public: 
    void push(int d);
    int top();
    void print();
    ListBasedPriorityQueue(){ head = NULL; }
    ~ListBasedPriorityQueue(){
        Node* cursor = head;
        while(cursor != NULL){
            free(cursor);
            cursor = cursor->next;
        }
    }
};

void ListBasedPriorityQueue::push(int d){
    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* cursor = head;
    while(cursor->next != NULL && newNode->data < cursor->next->data){
        cursor = cursor->next;
    }

    if(cursor == head && newNode->data >= cursor->data){
        newNode->next = head;
        head = newNode;
        return;
    }

    if(cursor->next != NULL)
        newNode->next = cursor->next;
    cursor->next = newNode;
}

int ListBasedPriorityQueue::top(){
    return head->data;
}

void ListBasedPriorityQueue::print(){
    Node* cursor = head;
    while(cursor != NULL){
        cout << cursor->data << ' ';
        cursor = cursor->next;
    }
    cout << '\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ListBasedPriorityQueue pq;

    pq.push(1);
    pq.push(9);
    pq.push(4);
    pq.push(7);
    pq.push(18);
    pq.push(3);
    
    cout << pq.top() << '\n';

    pq.print();
}