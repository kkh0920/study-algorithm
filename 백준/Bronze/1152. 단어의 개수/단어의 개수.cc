#include <iostream>
using namespace std;

int main(){
	
	int count = 0;
	int cnt;
	char arr[1000001];
	
	cin.getline(arr, 1000001,'\n');
	
	for(int i = 0; arr[i] != '\0'; i++){
		if(arr[i] == ' ' && i != 0 )
			count++;
		cnt = i;
	}
	if(arr[cnt] != ' ')
		count++;
	
	cout << count << '\n';
}