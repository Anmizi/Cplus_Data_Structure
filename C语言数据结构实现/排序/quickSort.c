#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *arr, int i, int j) {
	int temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}

int partition(int *arr, int l, int r) {
	int pivot = arr[l];
	int low = l;
	while (low < r) {
		while (low < r && arr[r] >= pivot)
			r--;
		while (low < r && arr[low] <= pivot)
			low++;
		if (low < r) {
			swap(arr, low, r);
		}
	}
	swap(arr, l, low);
	return low;
}

int partition1(int *arr, int low, int high) {
	int pivot = arr[low];
	int idx = low;
	int i = low + 1;
	for (; i <= high; i++) {
		if (arr[i] <= pivot) {
			idx++;
			swap(arr, idx, i);
		}
	}
	swap(arr, low, idx);
	return idx;
}

void quickSort(int *arr, int i, int j) {
	if (i < j) {
		int index = partition1(arr, i, j);
		quickSort(arr, i, index - 1);
		quickSort(arr, index + 1, j);
	}
}

//�������鳤������һ������Ԫ��Ϊ�����������
//@params n	���鳤��
//@params min ��Сֵ
//@params max ���ֵ
//@return res ��������ָ��
int *getArray(int n, int min, int max) {
	int *res = (int *)calloc(n, sizeof(int));
	srand((unsigned)time(NULL));
	int i = 0;
	for (; i < n; i++) {
		res[i] = rand() % (max - min + 1) + min;
	}
	return res;
}

int main() {
	int n = 0;
	printf("���������鳤��: ");
	scanf("%d", &n);
	int *res = getArray(n, 1, 100);
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	quickSort(res, 0, n - 1);
	printf("\n�������----------\n");
	for (i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}