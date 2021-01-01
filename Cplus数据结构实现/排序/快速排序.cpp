#include <iostream>
using namespace std;

void QuickSort(int r[], int i, int j);
int Partition(int r[], int i, int j);
int main() {
	int arr[10] = {3, 8, 2, 3, 4, 9, 2, 3, 4, 6};
	QuickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

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
		if (smallEle > bigEle)
			break;
		else {
			temp = r[smallEle];
			r[smallEle] = r[bigEle];
			r[bigEle] = temp;
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
	int parIndex = Partition(r, i, j);
	QuickSort(r, i, parIndex - 1);
	QuickSort(r, parIndex + 1, j);
}