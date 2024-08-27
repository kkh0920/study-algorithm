#include <iostream>
#include <vector>
using namespace std;

int N, arr[50][9], result = 0;

bool selected[9];
vector<int> order;

int getScore() {
    int score = 0, index = 0;
    for(int i = 0; i < N; i++) {
        int out = 0;
        bool one = false, two = false, three = false;
        while(out < 3) {
            switch(arr[i][order[index]]) {
                case 0:
                    out++;
                    break;
                case 1:
                    score += three;
                    three = two;
                    two = one;
                    one = true;
                    break;
                case 2:
                    score += three; score += two;
                    three = one; 
                    two = true;
                    one = false;
                    break;
                case 3:
                    score += three; score += two; score += one;
                    three = true;
                    two = false;
                    one = false;
                    break;
                case 4:
                    score += three; score += two; score += one; score++;
                    three = false;
                    two = false;
                    one = false;
                    break;
            }
            if(++index >= 9) index = 0;
        }
    }
    return score;
}

void select(int count) {
    if(count == 9) {
        result = max(result, getScore());
        return;
    }

    if(count == 3) {
        order.push_back(0);
        select(count + 1);
        order.pop_back();
        return;
    }

    for(int i = 1; i < 9; i++) {
        if(!selected[i]) {
            selected[i] = true;
            order.push_back(i);

            select(count + 1);
            
            selected[i] = false;
            order.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    select(0);

    cout << result << '\n';

    return 0;
}