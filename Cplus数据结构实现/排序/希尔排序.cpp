#include <iostream>
using namespace std;

void ShellSort(int r[], int n) {
	int temp;
	int incre = 2;
	int i, j, d;
	for (d = n / incre; d >= 1; d /= incre) {
		for (i = d; i < n; i++) {
			temp = r[i];
			for (j = i - d; j >= 0 && temp < r[j]; j -= d) {
				r[j + d] = r[j];
			}
			r[j + d] = temp;
		}
	}
}

int main() {
	int arr[10] = {7, 3, 8, 3, 9, 4, 2, 5, 3, 2};
	ShellSort(arr, 10);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
