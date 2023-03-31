#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> v[2], int s, int e, int m){
    vector<int> temp[2];
    int i = s, j = m + 1;
    while(i <= m && j <= e){
        if(v[0][i] < v[0][j]){
            temp[0].push_back(v[0][i]);
            temp[1].push_back(v[1][i]);
            i++;
        }
        else if(v[0][i] > v[0][j]){
            temp[0].push_back(v[0][j]);
            temp[1].push_back(v[1][j]);
            j++;
        }
        else{
            if(v[1][i] < v[1][j]){
                temp[0].push_back(v[0][i]);
                temp[1].push_back(v[1][i]);
                i++;
            }
            else{
                temp[0].push_back(v[0][j]);
                temp[1].push_back(v[1][j]);
                j++;
            }
        }
    }
    while(i <= m){
        temp[0].push_back(v[0][i]);
        temp[1].push_back(v[1][i]);
        i++;
    }
    while(j <= e){
        temp[0].push_back(v[0][j]);
        temp[1].push_back(v[1][j]);
        j++;
    }
    int c = 0;
    for(int k = s; k <= e; k++){
        v[0][k] = temp[0][c];
        v[1][k] = temp[1][c];
        c++;
    }

}

void mergeSort(vector<int> v[2], int s, int e){
    if(s < e){
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, e, m);
    }
}

int main(){
    vector<int> v[2];
    int i, n, x, y;

    cin >> n;

    for(i = 0; i < n; i++){
        cin >> x >> y;
        v[0].push_back(x);
        v[1].push_back(y);
    }
    mergeSort(v, 0, v[0].size() - 1);
    for(i = 0; i < v[0].size(); i++){
        cout << v[0][i] << ' ' << v[1][i] << '\n';
    }
}