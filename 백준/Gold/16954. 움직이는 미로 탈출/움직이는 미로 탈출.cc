#include <iostream>
using namespace std;

char arr[8][9], temp[8][9];
int result = 0;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void moveWall(){
    for(int i = 0; i < 8; i++){
        if(temp[7][i] == '#')
            temp[7][i] = '.';
    }
    for(int i = 6; i >= 0; i--){
        for(int j = 0; j < 8; j++){
            if(temp[i][j] == '#'){
                temp[i][j] = '.';
                temp[i + 1][j] = '#';
            }
        }
    }
}

void bfs(){
    bool isExist = true;
    while(isExist){
        isExist = false;
        if(arr[0][7] == 'P'){
            result = 1;
            return;
        }
        for(int curI = 0; curI < 8; curI++){
            for(int curJ = 0; curJ < 8; curJ++){
                if(arr[curI][curJ] == 'P'){
                    isExist = true;
                    for(int i = 0; i < 8; i++){
                        int nI = curI + dx[i];
                        int nJ = curJ + dy[i];
                        if(nI < 0 || nI >= 8 || nJ < 0 || nJ >= 8)
                            continue;
                        if(arr[nI][nJ] == '#')
                            continue;
                        temp[nI][nJ] = 'P';
                    }
                }
            }
        }

        moveWall();
        
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                arr[i][j] = temp[i][j];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> arr[i][j];
            temp[i][j] = arr[i][j];
        }
    }
    arr[7][0] = 'P';
    temp[7][0] = 'P';

    bfs();

    cout << result << '\n';
}
