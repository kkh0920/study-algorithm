#include <iostream>
using namespace std;

int main(){
	
	int num, cnt2 = 0;
	int arr[101];
	
	cin >> num;
	
	for(int i = 0; i < num; i++){
		cin >> arr[i];
	}
	
	for(int j = 0; j < num; j++){
		int cnt = 0;
		for(int i = 1; i <= arr[j]; i++){
			if(arr[j] % i == 0)
				cnt++;
		}
		if(cnt == 2)
			cnt2++;
	}
	
	cout << cnt2 << '\n';
}