#include <iostream>
using namespace std;

int number;
int sorted[1000001]; 

void merge(int a[], int m, int middle, int n) {

	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (a[i] < a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}

	if (i > middle) {
		for (int s = j; s <= n; s++) {
			sorted[k] = a[s];
			k++;
		}
	}
	else {
		for (int s = i; s <= middle; s++) {
			sorted[k] = a[s];
			k++;
		}
	}

	for (int s = m; s <= n; s++) {
		a[s] = sorted[s];
	}
}

void mergeSort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main() {
       
    int arr[1000001];
	
    cin >> number;	

	for (int i = 0; i < number; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, 0, number - 1);

	for (int i = 0; i < number; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}