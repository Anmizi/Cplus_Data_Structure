#include <stdio.h>

void InsertSort(int r[], int n) {
	int temp;
	int j;
	for (int i = 1; i < n; i++) {
		temp = r[i];
		for (j = i - 1; j >= 0 && temp < r[j]; j--) {
			r[j + 1] = r[j];
		}
		r[j + 1] = temp;
	}
}

int main(void) {
	int arr[10] = {4, 2, 3, 4, 7, 11, 9, 8, 2, 8};
	InsertSort(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
