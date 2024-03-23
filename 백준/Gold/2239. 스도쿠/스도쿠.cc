#include <iostream>
using namespace std;

char arr[9][9];
pair<int, int> nextPoint[9][9];

bool isPossible(char num, int curI, int curJ) {
    for(int i = 0; i < 9; i++) {
        if(arr[i][curJ] == num || arr[curI][i] == num)
            return false;
    }

    int si = (curI / 3) * 3;
    int sj = (curJ / 3) * 3;
    
    for(int i = si; i < si + 3; i++) {
        for(int j = sj; j < sj + 3; j++) {
            if(arr[i][j] == num)
                return false;
        }
    }
    
    return true;
}

bool search(int curI, int curJ) {
    int nextI = nextPoint[curI][curJ].first;
    int nextJ = nextPoint[curI][curJ].second;

    for(char c = '1'; c <= '9'; c++) {
        if(!isPossible(c, curI, curJ))
            continue;

        arr[curI][curJ] = c;
        
        if(nextI == -1 || nextJ == -1) 
            return true;
        if(search(nextI, nextJ))
            return true;
    }

    arr[curI][curJ] = '0';

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int prevI = -1, prevJ = -1, si = -1, sj = -1;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            nextPoint[i][j] = make_pair(-1, -1);

            cin >> arr[i][j];
            if(arr[i][j] != '0')
                continue;
            
            if(prevI != -1 && prevJ != -1)
                nextPoint[prevI][prevJ] = make_pair(i, j); 
            else {
                si = i;
                sj = j;
            }

            prevI = i;
            prevJ = j;
        }
    }

    if(si != -1 && sj != -1) {
        search(si, sj);
    }
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}