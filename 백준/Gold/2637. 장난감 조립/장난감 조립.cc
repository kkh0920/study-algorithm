#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector< pair<int, int> > graph[101], cache[101];

void dfs(int number) {
    if (cache[number].size() > 0) {
        return;
    }
    if (graph[number].size() == 0) {
        cache[number].push_back({number, 1});
        return;
    }

    for (auto &nextNode : graph[number]) {
        int numberNext = nextNode.first;
        int count = nextNode.second;
        
        dfs(numberNext);

        for (auto &cachedNode : cache[numberNext]) {
            bool isExist = false;
            for (auto &existingNode : cache[number]) {
                if (existingNode.first == cachedNode.first) {
                    existingNode.second += cachedNode.second * count;
                    isExist = true;
                    break;
                }
            }
            if (!isExist) {
                cache[number].push_back({
                    cachedNode.first,
                    cachedNode.second * count
                });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int x, y, k;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> k;
        graph[x].push_back({y, k});
    }

    dfs(N);

    sort(cache[N].begin(), cache[N].end());

    for (auto &result : cache[N]) {
        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}