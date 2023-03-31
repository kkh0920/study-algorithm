#include <iostream>
#include <string>
#include <queue>
using namespace std;

// Node 클래스 형의 queue를 이용한 bfs 알고리즘, 그래프 이론.

class Node{
public:    
    int data;
    string command;
    Node(string c, int d) { command = c; data = d; }
};

string str;
int T, A, B;
char command[4] = { 'D', 'S', 'L', 'R' };

Node DLSC(Node node, char c, int num){
    int operaton;
    switch(c){
        case 'D':
            operaton = num * 2 % 10000;
            break;
        case 'S':
            operaton = num != 0 ? num - 1 : 9999;
            break;
        case 'L':
            operaton = (num * 10) % 10000 + num / 1000;
            break;
        case 'R':
            operaton = (num / 10) + (num % 10) * 1000;
            break;
    }
    node.command += c;
    node.data = operaton;
    return node;
}

void search(Node node){
    bool check[10000] = { false };
    queue<Node> q;
    q.push(node);
    while(!q.empty()){
        Node n = q.front();
        check[n.data] = true;
        if(n.data == B){
            cout << n.command << '\n';
            return;
        }
        for(int i = 0; i < 4; i++){
            Node result = DLSC(n, command[i], n.data);
            if(result.data == B){
                cout << result.command << '\n';
                return;
            }
            if(!check[result.data]){
                check[result.data] = true;
                q.push(result);
            }
        }
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> A >> B;
        search(Node("", A));
    }
}