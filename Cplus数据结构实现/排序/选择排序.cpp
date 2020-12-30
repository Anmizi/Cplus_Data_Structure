#include <iostream>
using namespace std;

void SelectSort(int r[], int n) {
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (r[i] > r[j]) {
				temp = r[i];
				r[i] = r[j];
				r[j] = temp;

			}
		}
	}
}

int main() {
	int arr[10] = {3, 4, 2, 4, 7, 9, 4, 9, 7, 9};
	SelectSort(arr, 10);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}
