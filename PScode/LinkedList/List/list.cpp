#include <iostream>
using namespace std;

#include "list.h"

//클래스 내부 기능..

Node::Node(){
    next = NULL;
}
Node::Node(int d){
    data = d;
    next = NULL;
}

LinkedList::LinkedList(){
    head = NULL;
}

void LinkedList::addNode(int data){
    Node* new_Node = new Node(data);
    if(head == NULL){
        head = new_Node;
        return;
    }
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_Node;
    
}

void LinkedList::addfront(int data){
    Node* new_Node = new Node(data);
    if(head == NULL){
        head = new_Node;
        return;
    }
    new_Node->next = head;
    head = new_Node;
}

void LinkedList::deleteNode(int data){
    Node* cursor = head;
    Node* prevNode = NULL;
    while(cursor != NULL && cursor->data != data){
        prevNode = cursor;
        cursor = cursor->next; 
    }
    if(cursor == NULL){ //데이터가 없는 경우
        cout << data << " Not Found In List!" << '\n';
        return;
    }
    if(prevNode == NULL){ //head를 삭제해야하는 경우
        head = cursor->next;
    }
    else{
        prevNode->next = cursor->next;
    }
    free(cursor);
}

void LinkedList::printNode(){
    if(head == NULL){
        cout << "This List Is Empty!" << '\n';
        return;
    }
    Node* cursor = head;
    while(cursor != NULL){
        cout << cursor->data << ' ';
        cursor = cursor->next;
    }
    cout << '\n';
}