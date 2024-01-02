#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void postorder(Node* curNode) {
    if(curNode->data == 0)
        return;

    postorder(curNode->left);
    postorder(curNode->right);
    cout << curNode->data << '\n';

    delete curNode;
}

int main(){

    Node* root = new Node;
    root->data = 0;
    
    while(true) {
        int num;
        cin >> num;
        if(cin.eof())
            break;

        Node* cur = root;

        while(cur->data != 0) {
            if(num < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        
        cur->data = num;

        cur->left = new Node;
        cur->left->data = 0;

        cur->right = new Node;
        cur->right->data = 0;
    }

    postorder(root);

    return 0;
}