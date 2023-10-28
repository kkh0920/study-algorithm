#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int i, j, keys;
    Node(int I, int J){
        i = I;
        j = J;
        keys = 0;
    }
};

queue<Node> q;
char arr[50][51];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int N, M, result = 0;
bool visited[50][50][1 << 6];

void bfs(){
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node node = q.front();
            q.pop();

            if(arr[node.i][node.j] == '1')
                return;
            
            for(int j = 0; j < 4; j++){
                Node nNode = node;
                nNode.i = node.i + dx[j];
                nNode.j = node.j + dy[j];

                if(nNode.i < 0 || nNode.i >= N || nNode.j < 0 || nNode.j >= M)
                    continue;
                if(visited[nNode.i][nNode.j][nNode.keys] || arr[nNode.i][nNode.j] == '#')
                    continue;
                if(arr[nNode.i][nNode.j] >= 'A' && arr[nNode.i][nNode.j] <= 'F' 
                        && !(nNode.keys & (1 << int(arr[nNode.i][nNode.j] - 'A')))){
                    continue;
                }

                if(arr[nNode.i][nNode.j] >= 'a' && arr[nNode.i][nNode.j] <= 'f'){
                    nNode.keys |= (1 << int(arr[nNode.i][nNode.j] - 'a'));
                }
                visited[nNode.i][nNode.j][nNode.keys] = true;
                q.push(nNode);
            }
        } 
        result++;
    }
    result = -1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '0'){
                q.push(Node(i, j));
                visited[i][j][0] = true;
            }
        }
    }

    bfs();

    cout << result << '\n';
}   
