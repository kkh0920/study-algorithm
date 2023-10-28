#include <bits/stdc++.h>
using namespace std;

int r, c, t, arr[51][51], temp[51][51], curTime = 0, result = 0;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
pair<int, int> airFresh[2];

void freshAirUp(){
    for(int i = airFresh[0].first - 1; i > 1; i--)
        arr[i][1] = arr[i - 1][1]; 
    for(int i = 1; i < c; i++)
        arr[1][i] = arr[1][i + 1];
    for(int i = 1; i < airFresh[0].first; i++)
        arr[i][c] = arr[i + 1][c];
    for(int i = c; i > 2; i--)
        arr[airFresh[0].first][i] = arr[airFresh[0].first][i - 1];
    arr[airFresh[0].first][2] = 0; 
}

void freshAirDown(){
    for(int i = airFresh[1].first + 1; i < r; i++)
        arr[i][1] = arr[i + 1][1];
    for(int i = 1; i < c; i++)
        arr[r][i] = arr[r][i + 1];
    for(int i = r; i > airFresh[1].first; i--)
        arr[i][c] = arr[i - 1][c];
    for(int i = c; i > 2; i--)
        arr[airFresh[1].first][i] = arr[airFresh[1].first][i - 1];
    arr[airFresh[1].first][2] = 0;
}

void simulation(){    
    while(curTime < t){
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                if(arr[i][j] < 5)
                    continue;
                int cnt = 0;
                for(int k = 0; k < 4; k++){
                    int nI = i + dx[k];
                    int nJ = j + dy[k];
                    if(nI <= 0 || nI > r || nJ <= 0 || nJ > c)
                        continue;
                    if(arr[nI][nJ] == -1)
                        continue;
                    temp[nI][nJ] += arr[i][j] / 5;
                    cnt++;
                }
                temp[i][j] -= (arr[i][j] / 5) * cnt;
            }
        }

        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                arr[i][j] += temp[i][j];
                temp[i][j] = 0;
            }
        }

        freshAirUp();
        freshAirDown();
        
        curTime++;
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(arr[i][j] > 0)
                result += arr[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> t;

    int cnt = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> arr[i][j];
            if(cnt == 0 && arr[i][j] == -1){
                airFresh[0] = make_pair(i, j);
                airFresh[1] = make_pair(i + 1, j);
                cnt++;
            }
            temp[i][j] = 0;
        }
    }

    simulation();

    cout << result << '\n';
}