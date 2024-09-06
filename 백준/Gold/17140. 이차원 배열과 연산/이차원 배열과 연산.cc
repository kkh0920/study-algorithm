#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, k, arr[100][100], cnt[101];
int rl = 3, cl = 3;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void initCnt() {
    for(int i = 1; i <= 100; i++) {
        cnt[i] = 0;
    }
}

void unit_sort(vector< pair<int, int> > &v) {
    for(int j = 1; j <= 100; j++) {
        if(cnt[j]) v.push_back(make_pair(j, cnt[j]));
    }
    sort(v.begin(), v.end(), compare);
}

void row_sort_all() {
    int maxColLine = 0;
    for(int i = 0; i < rl; i++) {
        initCnt();
        for(int j = 0; j < cl; j++) {
            cnt[arr[i][j]]++;
        }

        vector< pair<int, int> > v;
        unit_sort(v);
        
        int index = 0;
        for(auto n : v) {
            arr[i][index++] = n.first;
            if(index >= 100) break;
            arr[i][index++] = n.second;
            if(index >= 100) break;
        }
        maxColLine = max(maxColLine, index);
        
        for(; index < cl; index++) {
            arr[i][index] = 0;
        }
    }
    cl = maxColLine;
}

void col_sort_all() {
    int maxRowLine = 0;
    for(int i = 0; i < cl; i++) {
        initCnt();
        for(int j = 0; j < rl; j++) {
            cnt[arr[j][i]]++;
        }

        vector< pair<int, int> > v;
        unit_sort(v);
        
        int index = 0;
        for(auto n : v) {
            arr[index++][i] = n.first;
            if(index >= 100) break;
            arr[index++][i] = n.second;
            if(index >= 100) break;
        }
        maxRowLine = max(maxRowLine, index);

        for(; index < rl; index++) {
            arr[index][i] = 0;
        }
    }
    rl = maxRowLine;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> k;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    
    int time = 0;
    while(arr[r - 1][c - 1] != k) {
        rl >= cl ? row_sort_all() : col_sort_all();
        if(++time > 100) {
            time = -1;
            break;
        }
    }

    cout << time << '\n';

    return 0;
}