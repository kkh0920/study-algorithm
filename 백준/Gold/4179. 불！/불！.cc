#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

vector< pair<int, int> > fv[2], temp;
queue< pair< int, pair<int, int> > > person;
queue< pair<int, int> > fire;
int r, c, maxT = 0, result = -1, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];

void init(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            visited[i][j] = false;
        }
    }
}

void prevFire(){
    while(!fire.empty())
        fire.pop();
    int size1 = fv[1].size();
    for(int j = 0; j < size1; j++){
        maze[fv[1][j].first][fv[1][j].second] = '.';
    }
    int size0 = fv[0].size();
    for(int i = 0; i < size0; i++){
        fire.push(make_pair(fv[0][i].first, fv[0][i].second));
    }
}

void bfs(){
    init();
    visited[person.front().second.first][person.front().second.second] = true;
    while(!person.empty()){ 
        int time = person.front().first;
        //불 확산
        if(!fire.empty()){
            int size = fire.size();
            while(size--){
                int fI = fire.front().first;
                int fJ = fire.front().second;
                fire.pop();
                for(int i = 0; i < 4; i++){
                    int nI = fI + dx[i];
                    int nJ = fJ + dy[i];
                    if(nI < 0 || nI >= r || nJ < 0 || nJ >= c)
                        continue;
                    if(maze[nI][nJ] == '#' || maze[nI][nJ] == 'F')
                        continue;
                    maze[nI][nJ] = 'F';
                    temp.push_back(make_pair(nI, nJ));
                    fire.push(make_pair(nI, nJ));
                }
            }
            if(!fv[1].empty()){
                fv[0] = fv[1];
                fv[1].clear();
            }
            int tSize = temp.size();
            for(int i = 0; i < tSize; i++){
                fv[1].push_back(temp[i]);
            }
            temp.clear();
        }

        //사람 이동
        bool isMove = false;
        int size = person.size();
        while(size--){
            int pI = person.front().second.first;
            int pJ = person.front().second.second;
            if(pI == 0 || pI == r - 1 || pJ == 0 || pJ == c - 1){
                if(time != 0)
                    prevFire();
                result = time + 1;
                return;
            }
            for(int i = 0; i < 4; i++){
                int nI = pI + dx[i];
                int nJ = pJ + dy[i];
                if(nI < 0 || nI >= r || nJ < 0 || nJ >= c)
                    continue;
                if(visited[nI][nJ] || maze[nI][nJ] == '#' || maze[nI][nJ] == 'F')
                    continue;
                visited[nI][nJ] = true;
                person.push(make_pair(time + 1, make_pair(nI, nJ)));
                isMove = true;
            }
            person.pop();
        }
        if(!isMove && time != 0)
            prevFire();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> maze[i][j];
            if(maze[i][j] == 'J')
                person.push(make_pair(0, make_pair(i, j)));
            if(maze[i][j] == 'F'){
                fire.push(make_pair(i, j));
                fv[0].push_back(make_pair(i, j));
            }
        }
    }

    bfs();

    if(result == -1)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << result << '\n';
}