#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool has[1000], cost[1000];
priority_queue<int, vector<int>, greater<int>> pq;

int solution(int coin, vector<int> cards) {
    int answer = 1;
    int n = cards.size();
    int index = n / 3;

    for (int i = 0; i < index; i++) {
        has[cards[i]] = true;
        if (has[n + 1 - cards[i]]) {
            pq.push(0);
        }
    }

    for (int i = index; i < n; i++) {
        has[cards[i]] = true;
        cost[cards[i]] = true;
        if (has[n + 1 - cards[i]]) {
            pq.push(cost[cards[i]] + cost[n + 1 - cards[i]]);
        }
        if (i % 2 == 0) {
            continue;
        }
        if (pq.empty() || coin < pq.top()) {
            break;
        }
        answer++;
        coin -= pq.top();
        pq.pop();
    }
    
    return answer;
}