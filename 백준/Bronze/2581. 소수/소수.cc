#include <iostream>
using namespace std;

int main(){
	
	int num1, num2, min, sum = 0, count = 0;
	
	cin >> num1 >> num2;
	
	for(int i = num1; i <= num2; i++){
		int cnt = 0;
		for(int j = 1; j <= i; j++){
			if(i % j == 0)
				cnt++;
		}
		if(cnt == 2){
			sum += i;
			if(count == 0){
				count++;
				min = i;
			}
		}
	}
	
	if(sum == 0)
		cout << -1;
		
	else{
		cout << sum << '\n';
		cout << min << '\n';
	}
}