#include <iostream>
using namespace std;

#include "list.h"

int main(){
    // 실제 사용 예시.
    LinkedList* myList = new LinkedList();
    
    myList->addNode(10);
    myList->addNode(20);
    myList->addNode(30);
    myList->addfront(45);

    myList->printNode();

    myList->deleteNode(30);

    myList->printNode();

    myList->deleteNode(20);
    
    myList->printNode();

    myList->deleteNode(10);

    myList->printNode();

    myList->deleteNode(30);

    myList->printNode();

    myList->deleteNode(45);

    myList->printNode();

    return 0;
}
