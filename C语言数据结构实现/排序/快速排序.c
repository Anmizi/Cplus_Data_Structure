#include <stdio.h>

int Partition(int r[], int i, int j) {
	int pivot = r[j];
	int smallEle = i;
	int bigEle = j - 1;
	int temp;
	while (1) {
		while (smallEle < j && r[smallEle] <= pivot)
			smallEle++;
		while (bigEle >= i && r[bigEle] > pivot)
			bigEle--;
		if (smallEle > bigEle) {
			break;
		} else {
			temp = r[bigEle];
			r[bigEle] = r[smallEle];
			r[smallEle] = temp;
		}
	}
	temp = r[smallEle];
	r[smallEle] = r[j];
	r[j] = temp;
	return smallEle;
}

void QuickSort(int r[], int i, int j) {
	if (i >= j)
		return;
	int partitionIndex = Partition(r, i, j);
	QuickSort(r, i, partitionIndex - 1);
	QuickSort(r, partitionIndex + 1, j);
}

int main(void) {
	int arr[10] = {5, 4, 3, 6, 7, 3, 4, 6, 9, 6};
	QuickSort(arr, 0, 9);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}


	return 0;
}
