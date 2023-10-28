#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, i, j, c1 = 0, c2 = 0, result = 65, r;
    char arr[50][51], Bfirst = 'B', WFirst = 'W', tmp;
    
    cin >> N >> M;

    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    int cur1, cur2;
    for(cur2 = 0; cur2 + 8 <= N; cur2++){
        for(cur1 = 0; cur1 + 8 <= M; cur1++){
            for(i = cur2; i < cur2 + 8; i++){ 
                for(j = cur1; j < cur1 + 8; j++){
                    if(arr[i][j] != Bfirst) 
                        c1++; 
                    else 
                        c2++;
                    tmp = Bfirst;
                    Bfirst = WFirst;
                    WFirst = tmp;
                }
                tmp = Bfirst;
                Bfirst = WFirst;
                WFirst = tmp;
            }
            r = c1 > c2 ? c2 : c1;
            result = result > r ? r : result;
            c1 = 0;
            c2 = 0;
            Bfirst = 'B';
            WFirst = 'W';
        }
    }
    
    cout << result << '\n';
}