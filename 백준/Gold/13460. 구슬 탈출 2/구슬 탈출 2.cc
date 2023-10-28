#include <bits/stdc++.h>
using namespace std;

class State{
public:
    int redI, redJ;
    int blueI, blueJ;
    State(int rI, int rJ, int bI, int bJ){
        redI = rI; redJ = rJ;
        blueI = bI; blueJ = bJ;
    }
};

queue<State> q;
pair<int, int> nR, nB;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int N, M, result = 0;
char arr[10][11];

int moveRed(int curI, int curJ, int i, int bI, int bJ){
    int nI = curI + dx[i];
    int nJ = curJ + dy[i];
    while(arr[nI][nJ] != '#'){
        if(arr[nI][nJ] == 'O')
            return 1;
        if(nI == bI && nJ == bJ)
            break;
        nI += dx[i];
        nJ += dy[i];
    }
    
    nR.first = nI - dx[i];
    nR.second = nJ - dy[i];
    
    return 0;
}

int moveBlue(int curI, int curJ, int i, int rI, int rJ){
    int nI = curI + dx[i];
    int nJ = curJ + dy[i];
    int RI = rI;
    int RJ = rJ;
    while(arr[nI][nJ] != '#'){
        if(arr[nI][nJ] == 'O')
            return -1;

        if(nI == RI && nJ == RJ){
            if(arr[RI + dx[i]][RJ + dy[i]] == '#')
                break;
            if(arr[RI + dx[i]][RJ + dy[i]] == 'O')
                return -1;
            
            RI += dx[i];
            RJ += dy[i]; 
        }
        nI += dx[i];
        nJ += dy[i];
    }
    
    nR.first = RI;
    nR.second = RJ;
    nB.first = nI - dx[i];
    nB.second = nJ - dy[i];

    return 0;
}

void bfs(){
    while(!q.empty()){
        result++;
        if(result > 10){
            result = -1;
            return;
        }

        int size = q.size();
        for(int i = 0; i < size; i++){
            int curRI = q.front().redI;
            int curRJ = q.front().redJ;
            int curBI = q.front().blueI;
            int curBJ = q.front().blueJ;
            q.pop();
        
            for(int i = 0; i < 4; i++){
                int b = moveBlue(curBI, curBJ, i, curRI, curRJ);
                if(b == -1)
                    continue;
                
                int r = moveRed(nR.first, nR.second, i, nB.first, nB.second);
                if(r == 1)
                    return;
                
                if(curRI == nR.first && curRJ == nR.second && curBI == nB.first && curBJ == nB.second)
                    continue;
                
                q.push(State(nR.first, nR.second, nB.first, nB.second));
            }
        }
    }
    result = -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int ri, rj, bi, bj;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'R'){
                ri = i;
                rj = j;
            }
            if(arr[i][j] == 'B'){
                bi = i;
                bj = j;
            }
        }
    }

    q.push(State(ri, rj, bi, bj));

    bfs();

    cout << result << '\n';
}