#include <bits/stdc++.h>
using namespace std;

//BOJ 13460
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

//빨간 구슬 이동
int moveRed(int curI, int curJ, int i, int bI, int bJ){
    int nI = curI + dx[i];
    int nJ = curJ + dy[i];
    while(arr[nI][nJ] != '#'){
        /* 이미 파란 구슬을 굴려서 더이상 움직이지 못하는 상태이므로, 
           빨간 구슬이 구멍에 들어가면 게임 끝, 파란 구슬을 만나면 break */
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

//파란 구슬 이동
int moveBlue(int curI, int curJ, int i, int rI, int rJ){
    int nI = curI + dx[i];
    int nJ = curJ + dy[i];
    int RI = rI;
    int RJ = rJ;
    while(arr[nI][nJ] != '#'){
        //파란 구슬이 구멍에 들어가면 -1 을 return
        if(arr[nI][nJ] == 'O')
            return -1;
        
        //빨간 구슬을 만나면, 같이 굴러감
        if(nI == RI && nJ == RJ){

            //같이 굴러가는 빨간 구슬이 벽을 만나면 break
            if(arr[RI + dx[i]][RJ + dy[i]] == '#')
                break;

            /* 같이 굴러가는 빨간 구슬이 구멍에 들어간다는 것은, 
               파란 구슬도 같이 구멍에 들어갈 것을 암시하므로 -1 을 return */
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

//너비 우선 탐색
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
                //파란 구슬을 먼저 이동.
                int b = moveBlue(curBI, curBJ, i, curRI, curRJ);
                if(b == -1)
                    continue;
                
                //빨간 구슬을 차후 이동.
                int r = moveRed(nR.first, nR.second, i, nB.first, nB.second);
                if(r == 1)
                    return;
                
                //빨간 구슬과, 파란 구슬 모두 이동하지 못하면 패스(백트래킹)
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

    //초기 구슬의 상태를 저장
    q.push(State(ri, rj, bi, bj));

    bfs();

    cout << result << '\n';
}