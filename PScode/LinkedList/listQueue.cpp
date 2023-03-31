#include <iostream>
using namespace std;

// 리스트를 이용한 queue
class queue{
public:
    class Node{
    public:
        int data;
        Node* next;
        Node(int d){ data = d; }
    };
    Node *head;
    void push(int d);
    void pop();
    int front();
    void print();
    bool empty();
    queue(){ head = NULL; }
    ~queue(){ while(!empty()) pop(); }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 5;
    while(cnt--){
        queue q;
        q.push(2);
        q.print();
    }
}

void queue::push(int d){
    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

void queue::pop(){
    if(head == NULL){
        cout << "Empty!" << '\n';
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

int queue::front(){ return head->data; }

void queue::print(){
    if(head == NULL){
        cout << "Empty!" << '\n';
        return;
    }
    Node* cursor = head;
    while(cursor != NULL){
        cout << cursor->data << ' ';
        cursor = cursor->next;
    }
    cout << '\n';
}

bool queue::empty(){ 
    return head == NULL;
}