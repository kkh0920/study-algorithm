#include <iostream>
#include <queue>
#define MAXN 1000
using namespace std;

bool visited[MAXN][MAXN][2] = { false };
char arr[MAXN][MAXN + 1];
int N, M, result = MAXN * MAXN;

class Node{
public:
    int nodeI, nodeJ, moveCnt;
    bool isWallBreak;
    Node(int i, int j, bool wb, int mc){
        nodeI = i; nodeJ = j; moveCnt = mc;
        isWallBreak = wb;
    }
};

queue<Node> q;

void bfs(){
    while(!q.empty()){
        int i = q.front().nodeI, j = q.front().nodeJ;
        int move = q.front().moveCnt + 1;
        bool isWallBreak = q.front().isWallBreak;

        if(q.front().nodeI == N - 1 && q.front().nodeJ == M - 1){
            result = q.front().moveCnt < result ? q.front().moveCnt : result;
            q.pop();
            continue;
        }
        if(visited[i][j][isWallBreak]){
            q.pop();
            continue;
        }

        if(i > 0){
            if(arr[i - 1][j] == '0')
                q.push(Node(i - 1, j, isWallBreak, move));
            else if(arr[i - 1][j] == '1' && !isWallBreak)
                q.push(Node(i - 1, j, true, move));
        }
        if(i < N - 1){
            if(arr[i + 1][j] == '0')
                q.push(Node(i + 1, j, isWallBreak, move));
            else if(arr[i + 1][j] == '1' && !isWallBreak)
                q.push(Node(i + 1, j, true, move));
        }
        if(j > 0){
            if(arr[i][j - 1] == '0')
                q.push(Node(i, j - 1, isWallBreak, move));
            else if(arr[i][j - 1] == '1' && !isWallBreak)
                q.push(Node(i, j - 1, true, move));
        }
        if(j < M - 1){
            if(arr[i][j + 1] == '0')
                q.push(Node(i, j + 1, isWallBreak, move));
            else if(arr[i][j + 1] == '1' && !isWallBreak)
                q.push(Node(i, j + 1, true, move));
        }
        
        visited[i][j][isWallBreak] = true;
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char num[MAXN + 1];

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> num;
        for(int j = 0; j < M; j++){
            arr[i][j] = num[j];
        }
    }

    q.push(Node(0, 0, false, 1));

    bfs();

    if(result == MAXN * MAXN)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}