#include <iostream>
using namespace std;

int arr[500][500], N, M;

int search(){
    int max = 0, temp;
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < M - 1; j++){
            temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
            max = temp > max ? temp : max;
        }
    }
    for(int i = 0; i < N - 2; i++){
        for(int j = 0; j < M; j++){
            temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
            for(int k = i; k < i + 3; k++){
                if(j > 0)
                    max = temp + arr[k][j - 1] > max ? temp + arr[k][j - 1] : max;
                if(j < M - 1)    
                    max = temp + arr[k][j + 1] > max ? temp + arr[k][j + 1] : max;
            }
            if(i < N - 3)
                max = temp + arr[i + 3][j] > max ? temp + arr[i + 3][j] : max;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M - 2; j++){
            temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
            for(int k = j; k < j + 3; k++){
                if(i > 0)
                    max = temp + arr[i - 1][k] > max ? temp + arr[i - 1][k] : max;
                if(i < N - 1)    
                    max = temp + arr[i + 1][k] > max ? temp + arr[i + 1][k] : max;
            }
            if(j < M - 3)
                max = temp + arr[i][j + 3] > max ? temp + arr[i][j + 3] : max;
        }
    }
    int tmp1, tmp2;
    for(int i = 0; i < N - 1; i++){
        for(int j = 1; j < M - 1; j++){
            temp = arr[i][j] + arr[i + 1][j];
            tmp1 = arr[i][j - 1] + arr[i + 1][j + 1];
            tmp2 = arr[i + 1][j - 1] + arr[i][j + 1];
            
            max = temp + tmp1 > max ? temp + tmp1 : max;
            max = temp + tmp2 > max ? temp + tmp2 : max;
        }
    }
    for(int i = 1; i < N - 1; i++){
        for(int j = 0; j < M - 1; j++){
            temp = arr[i][j] + arr[i][j + 1];
            tmp1 = arr[i - 1][j] + arr[i + 1][j + 1];
            tmp2 = arr[i + 1][j] + arr[i - 1][j + 1];
            
            max = temp + tmp1 > max ? temp + tmp1 : max;
            max = temp + tmp2 > max ? temp + tmp2 : max;
        }
    }
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    
    cout << search() << '\n';
}