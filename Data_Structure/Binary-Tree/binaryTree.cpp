#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

//완전 이진 트리(왼쪽부터 노드가 순서대로 채워짐).
class BinaryTree{
    Node* root = NULL;
    Node* createNode(int d);
    void freePostorder(Node* cur);
public:
    BinaryTree(){}
    ~BinaryTree(){ freePostorder(root); }

    Node* getRootNode() { return root; }

    void insertNode(int d);

    void preorder(Node* cur);
    void inorder(Node* cur);
    void postorder(Node* cur);
};

Node* BinaryTree::createNode(int d){
    Node* newNode = new Node();
    if(!newNode){
        cout << "Memory Error!\n";
        return NULL;
    }
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void BinaryTree::insertNode(int d){
    if(root == NULL){
        root = createNode(d);
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        if(cur->left == NULL){
            cur->left = createNode(d);
            return;
        }
        q.push(cur->left);
        if(cur->right == NULL){
            cur->right = createNode(d);
            return;
        }
        q.push(cur->right);
    }
}

void BinaryTree::preorder(Node* cur){
    if(cur == NULL)
        return;
    cout << cur->data << ' ';
    preorder(cur->left);
    preorder(cur->right);
}

void BinaryTree::inorder(Node* cur){
    if(cur == NULL)
        return;
    inorder(cur->left);
    cout << cur->data << ' ';
    inorder(cur->right);
}

void BinaryTree::postorder(Node* cur){
    if(cur == NULL)
        return;
    postorder(cur->left);
    postorder(cur->right);
    cout << cur->data << ' ';
}

void BinaryTree::freePostorder(Node* cur){
    if(cur == NULL)
        return;
    freePostorder(cur->left);
    freePostorder(cur->right);
    free(cur);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BinaryTree bt;

    bt.insertNode(1);
    bt.insertNode(2);
    bt.insertNode(3);
    bt.insertNode(4);
    bt.insertNode(5);
    bt.insertNode(6);
    bt.insertNode(7);

    bt.preorder(bt.getRootNode());
    cout << '\n';
    bt.inorder(bt.getRootNode());
    cout << '\n';
    bt.postorder(bt.getRootNode());
    cout << '\n';
}