#include <bits/stdc++.h>
using namespace std;

int k, v, e;
bool result = true;
int check[20001] = { 0 };
vector<int> graph[20001];

void dfs(int start, int num){
    int size = graph[start].size();
    for(int i = 0; i < size; i++){
        int nextNum, nextNode = graph[start][i];
        if(check[nextNode]){
            if(check[nextNode] == num)
                result = false;
            continue;
        }

        if(num == 1)
            nextNum = 2;
        else
            nextNum = 1;

        check[nextNode] = nextNum;

        dfs(nextNode, nextNum);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    
    int start, end;
    for(int i = 0; i < k; i++){
        cin >> v >> e;
        
        string s = "YES";
        result = true;
        fill(check, check + (v + 1), 0);
        for(int i = 1; i <= v; i++)
            graph[i].clear();

        for(int j = 0; j < e; j++){
            cin >> start >> end;
            graph[start].push_back(end);
            graph[end].push_back(start);
        }

        for(int i = 1; i <= v; i++){
            if(!check[i]){
                check[i] = 1;
                dfs(i, 1);
            }
            if(result == false){
                s = "NO";
                break;
            }
        }
        cout << s << '\n';
    }
}