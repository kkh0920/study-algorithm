#include <bits/stdc++.h>
using namespace std;

//BOJ 16236
class Shark{
public:
    int i, j;
    int size;
    int time;
    int exp;
    Shark(int si, int sj, int s, int t, int e){
        i = si; j = sj;
        size = s; time = t;
        exp = e;
    }
};

queue<Shark> q;
vector<Shark> temp;
int n, arr[20][20], result = 0;
int dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 };
bool visited[20][20];

void initVisited(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
}

bool isPrior(Shark s1, Shark s2){
    if(s1.i > s2.i)
        return true;
    else if(s1.i == s2.i){
        if(s1.j > s2.j)
            return true;
        return false;
    }
    return false;
}

Shark priorShark(){
    Shark prior = temp[0];
    for(int i = 1; i < temp.size(); i++){
        prior = isPrior(prior, temp[i]) ? temp[i] : prior;
    }
    temp.clear();
    return prior;
}

void synchronize(){
    while(!q.empty())
        q.pop();

    q.push(priorShark());

    initVisited();
    visited[q.front().i][q.front().j] = true;
    arr[q.front().i][q.front().j] = 0;

    result = q.front().time;
}

void bfs(){
    int prevTime;
    bool isEat = false;
    while(!q.empty()){
        int curI = q.front().i;
        int curJ = q.front().j;
        int time = q.front().time;
        int sharkSize = q.front().size;
        int exp = q.front().exp;
        q.pop();

        if(isEat && time > prevTime){
            synchronize();
            isEat = false;
            continue;
        }

        for(int i = 0; i < 4; i++){
            int nI = curI + dx[i];
            int nJ = curJ + dy[i];
            if(nI < 0 || nI >= n || nJ < 0 || nJ >= n)
                continue;
            if(visited[nI][nJ] || arr[nI][nJ] > sharkSize)
                continue;
            
            visited[nI][nJ] = true;
            q.push(Shark(nI, nJ, sharkSize, time + 1, exp));
            
            if(arr[nI][nJ] != 0 && arr[nI][nJ] < sharkSize){
                prevTime = time;
                isEat = true;
                if(sharkSize == exp + 1)
                    temp.push_back(Shark(nI, nJ, sharkSize + 1, time + 1, 0));
                else
                    temp.push_back(Shark(nI, nJ, sharkSize, time + 1, exp + 1));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            visited[i][j] = false;
            if(arr[i][j] == 9){
                arr[i][j] = 0;
                q.push(Shark(i, j, 2, 0, 0));
                visited[i][j] = true;
            }
        }
    }

    bfs();
    
    cout << result << '\n';
}

