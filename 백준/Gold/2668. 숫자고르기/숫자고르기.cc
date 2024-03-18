#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[101], result[101], cnt = 0;
bool isCycled[101], checked[101], cycle;

int search(int node) {
    if(checked[node])
        return -1;
    if(isCycled[node])
        return node;

    isCycled[node] = true;
    
    int num = search(arr[node]);

    isCycled[node] = false;

    if(num == -1)
        return -1;

    if(cycle) {
        checked[node] = true;
        result[cnt++] = node;
    }
    if(num == node)
        cycle = false;

    return num;
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++) {
        if(checked[i])
            continue;

        cycle = true;
        isCycled[i] = true;
        
        int num = search(arr[i]);
        
        isCycled[i] = false;

        if(num == -1)
            continue;
        
        if(cycle) {
            checked[i] = true;
            result[cnt++] = i;
        }
    }

    sort(result, result + cnt);

    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++) {
        cout << result[i] << '\n';
    }

    
    return 0;
}