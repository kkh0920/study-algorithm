#ifndef LIST_H
#define LIST_H

// 클래스 기능 종류
class Node{
public:
    int data;
    Node* next;
    Node();
    Node(int d);
};

class LinkedList{
private:
    Node* head;
public:
    void addNode(int data);
    void addfront(int data);
    void deleteNode(int data);
    void printNode();
    LinkedList();
};
#endif