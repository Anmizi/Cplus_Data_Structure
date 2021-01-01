#include <stdio.h>

//改进后的排序算法
void BubbleSort(int r[], int n) {
	int temp;
	int flag = 1;
	int i = 1;
	while (flag) {
		flag = 0;
		for (int j = 0; j < n - i; j++) {
			if (r[j] > r[j + 1]) {
				temp = r[j + 1];
				r[j + 1] = r[j];
				r[j] = temp;
				flag = 1;
			}
		}
		i++;
	}
}

void Bubble_sort(int r[], int n) {
	int temp;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (r[j] > r[j + 1]) {
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
			}
		}
	}
}

int main(void) {
	int arr[10] = {9, 8, 5, 3, 7, 8, 4, 6, 7, 9};
//	BubbleSort(arr, 10);
	Bubble_sort(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
