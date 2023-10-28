#include <bits/stdc++.h>
#define MAXN 20
#define WALL 10000
using namespace std;

queue< pair<int, int> > driver;
pair<int, int> destination[MAXN * MAXN + 1];

int arr[MAXN + 1][MAXN + 1], N, M, fuel;
bool visited[MAXN + 1][MAXN + 1];
int dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 };

void initVisited(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            visited[i][j] = false;
        }
    }
}

bool moveToDestination(int destI, int destJ){
    initVisited();
    visited[driver.front().first][driver.front().second] = true;

    int time = 0;
    while(!driver.empty()){
        int size = driver.size();
        for(int i = 0; i < size; i++){
            int curI = driver.front().first;
            int curJ = driver.front().second;
            driver.pop();

            if(curI == destI && curJ == destJ){
                fuel += time * 2;

                while(!driver.empty())
                    driver.pop();

                driver.push(make_pair(curI, curJ));
                
                return true;
            }

            if(fuel == 0)
                continue;

            for(int j = 0; j < 4; j++){
                int nI = curI + dx[j];
                int nJ = curJ + dy[j];
                if(nI < 1 || nI > N || nJ < 1 || nJ > N)
                    continue;
                if(visited[nI][nJ] || arr[nI][nJ] == WALL)
                    continue;
                visited[nI][nJ] = true;
                driver.push(make_pair(nI, nJ));
            }
        }
        time++;
        fuel--;
    }
    return false;
}

bool findPerson(){
    initVisited();
    visited[driver.front().first][driver.front().second] = true;

    int pI = 21, pJ = 21;
    while(!driver.empty()){
        int size = driver.size();
        for(int i = 0; i < size; i++){
            int curI = driver.front().first;
            int curJ = driver.front().second;
            driver.pop();

            if(!fuel)
                return false;

            if(arr[curI][curJ] != 0){
                if(curI < pI || (curI == pI && curJ < pJ)){
                    pI = curI;
                    pJ = curJ;
                }
            }

            for(int j = 0; j < 4; j++){
                int nI = curI + dx[j];
                int nJ = curJ + dy[j];
                if(nI < 1 || nI > N || nJ < 1 || nJ > N)
                    continue;
                if(visited[nI][nJ] || arr[nI][nJ] == WALL)
                    continue;
                visited[nI][nJ] = true;
                driver.push(make_pair(nI, nJ));
            }
        }

        if(pI != 21){
            int di = destination[arr[pI][pJ]].first;
            int dj = destination[arr[pI][pJ]].second;

            arr[pI][pJ] = 0;

            while(!driver.empty())
                driver.pop();

            driver.push(make_pair(pI, pJ));

            return moveToDestination(di, dj);
        }

        fuel--;
    }
    return false;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> fuel;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1)
                arr[i][j] = WALL;
        }
    }

    int a, b;
    cin >> a >> b;
    driver.push(make_pair(a, b));

    int sI, sJ, eI, eJ;
    for(int i = 1; i <= M; i++){
        cin >> sI >> sJ >> eI >> eJ;

        arr[sI][sJ] = i;

        destination[i] = make_pair(eI, eJ);
    }

    int cnt = M;
    while(cnt--){
        if(!findPerson()){
            fuel = -1;
            break;
        }
    }

    cout << fuel << '\n';
}