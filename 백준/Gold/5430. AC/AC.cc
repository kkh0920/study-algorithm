#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    deque<string> d;
    int t, n, cnt;
    string p, arr, temp;
    bool isReverse;

    cin >> t;
    for(int i = 0; i < t; i++){
        cnt = 0;
        isReverse = false;
        for(int j = 0; d.size() != 0; j++){
            d.pop_front();
        }

        cin >> p >> n >> arr;

        for(int j = 1; j < arr.length() - 1; j++){
            temp = "";
            do {
                if(arr[j] == ',' || arr[j] == ']')
                    break;
                temp = temp.append(arr, j, 1);
                j++;
            } while(arr[j] != ',' && arr[j] != ']');
            d.push_back(temp);   
        }

        for(int j = 0; j < p.length(); j++){
            if(p[j] == 'D')
                cnt++;
        }
        if(cnt > d.size()){
            cout << "error" << '\n';
            continue;
        }

        for(int j = 0; j < p.length(); j++){
            if(p[j] == 'R')
                isReverse = isReverse ? false : true;
            else if(p[j] == 'D'){
                if(isReverse)
                    d.pop_back();
                else
                    d.pop_front();
            }
        }   

        deque<string>::iterator s = isReverse ? d.rbegin().base() - 1 : d.begin();
        deque<string>::iterator e = isReverse ? d.rend().base() - 1 : d.end();

        cout << '[';
        while(s != e){
            cout << *s;
            if(s < e - 1 || s > e + 1)
                cout << ',';
            s += s > e ? -1 : 1;
        }
        cout << ']' << '\n';
    }
}