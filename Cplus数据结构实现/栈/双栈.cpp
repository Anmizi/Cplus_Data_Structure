#include <iostream>
using namespace std;
template <class T>
class DStack {
		T *Data;
		int top1;
		int top2;
		int MaxSize;
	public:
		DStack(int n);
		void Push(T item, int Tag);
		T Pop(int Tag);
		void PrintStack(int Tag);
};
template <class T>

DStack<T>::DStack(int n) {
	MaxSize = n;
	top1 = -1;
	top2 = MaxSize;
}
template <class T>

void DStack<T>::Push(T item, int Tag) {
	if (top1 + 1 == top2) {
		cout << "ջ��" << endl;
	} else {
		if (Tag == 1) {
			Data[++top1] = item;
		} else {
			Data[--top2] = item;
		}
	}
}
template <class T>

T DStack<T>::Pop(int Tag) {
	if (Tag == 1) {
		if (top1 == -1) {
			cout << "��ջ1��" << endl;
			return 0;
		} else {
			top1--;
		}
	} else {
		if (top2 == MaxSize) {
			cout << "��ջ2��" << endl;
			return 0;
		} else {
			top2++;
		}
	}
}
template <class T>

void DStack<T>::PrintStack(int Tag) {
	if (Tag == 1) {
		if (top1 == -1) {
			cout << "��ջ1��";
		} else {
			while (top1 != -1) {
				cout << Data[top1--] << " ";
			}
		}
	} else {
		if (top2 == MaxSize) {
			cout << "��ջ2��";
		} else {
			while (top2 != MaxSize) {
				cout << Data[top2++] << " ";
			}
		}
	}
}

int main() {
	DStack<int> *stack = new DStack<int>(11);
//	DStack<int> stack(11);
	int j = 1;
	for (int i = 0; i < 10; i++) {
		stack->Push(i, j);
		j = -j;
	}
	//��ӡ�����ջ1
	stack->PrintStack(1);
	cout << endl;
	//��ӡ�����ջ2
	stack->PrintStack(2);
	return 0;
}
