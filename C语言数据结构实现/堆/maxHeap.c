#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MaxSize 100
#define bool int
#define true 1
#define false 0

typedef struct HeapStruct {
	int *elements;
	int size;
	int maxsize;
} *MaxHeap;
//函数声明

MaxHeap Create(int);
bool Insert(MaxHeap, int);
int *getArray(int, int, int);
bool isFull(MaxHeap);
bool isEmpty(MaxHeap);
int DeleteMax(MaxHeap H);
void swap(MaxHeap, int i, int j);
void printHeap(MaxHeap);
//函数声明结束
MaxHeap Create(int maxsize) {
	MaxHeap H = malloc(sizeof(struct HeapStruct));
	H->elements = malloc(maxsize * sizeof(int));
	H->size = 0;
	H->maxsize = maxsize;
	return H;
}

bool Insert(MaxHeap H, int item) {
	if (isFull(H))
		return false;
	if (H->size == 0) {
		H->elements[H->size++] = item;
	} else {
		int i = H->size++;
		while (i > 0 && H->elements[(i - 1) / 2] < item) {
			H->elements[i] = H->elements[(i - 1) / 2];
			i = (i - 1) / 2;
		}
		H->elements[i] = item;
	}
	return true;

}

int DeleteMax(MaxHeap H) {
	if (isEmpty(H)) {
		printf("最大堆已空");
		return -1;
	}
	int maxValue = H->elements[0];
	H->elements[0] = H->elements[--H->size];
	int i = 0;
	int mxIdx = i;
	while (true) {
		if (
		    2 * i + 1 < H->size
		    &&
		    H->elements[2 * i + 1] > H->elements[mxIdx]) {
			mxIdx = 2 * i + 1;
		}
		if (
		    2 * i + 2 < H->size
		    &&
		    H->elements[2 * i + 2] > H->elements[mxIdx]
		) {
			mxIdx = 2 * i + 2;
		}
		//当前孩子节点值都比父节点值小时，不再往下堆化
		if (mxIdx == i)
			break;
		swap(H, i, mxIdx);
		i = mxIdx;
	}
	return maxValue;

}

//获取指定大小的随机数数组
int *getArray(int n, int min, int max) {
	int *res = (int *)calloc(n, sizeof(int));
	srand((unsigned)time(NULL));
	int i = 0;
	for (; i < n; i++) {
		res[i] = rand() % (max - min + 1) + min;
	}
	return res;
}

bool isFull(MaxHeap H) {
	return H->size == H->maxsize;
}

bool isEmpty(MaxHeap H) {
	return H->size == 0;
}

void swap(MaxHeap H, int i, int j) {
	int temp = H->elements[i];
	H->elements[i] = H->elements[j];
	H->elements[j] = temp;
}

void printHeap(MaxHeap p) {
	printf("\n\r***开始打印堆元素***\n\r");
	int i;
	for (i = 0; i < p->size; i++) {
		printf("%d ", p->elements[i]);
	}
}

int main() {
	MaxHeap p = Create(MaxSize);
	int n = 10;
	int i;
	int *arr = getArray(n, 1, 20);

	for (i = 0; i < n; i++) {
		Insert(p, arr[i]);
		printf("%d ", arr[i]);
	}
	printHeap(p);
	DeleteMax(p);
	printHeap(p);

	return 0;
}