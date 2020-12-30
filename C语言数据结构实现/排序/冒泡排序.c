#include <stdio.h>

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

int main(void) {
	int arr[10] = {2, 3, 4, 5, 8, 7, 8, 7, 4, 8};
	BubbleSort(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
