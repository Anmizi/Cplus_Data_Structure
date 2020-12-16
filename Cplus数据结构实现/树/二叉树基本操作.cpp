#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

template <class T>
struct BiNode {
	T data;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
};
template <class T>

class BiTree {
	private:
		BiNode<T> *root;
		BiNode<T> *CreateByPre(vector<T> &pre, int &i);
		BiNode<T> *CreateByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n);
		void PreOrder(BiNode<T> *p);	//ǰ�����
		void InOrder(BiNode<T> *p);		//�������
		void PostOrder(BiNode<T> *p);	//�������
		int Height(BiNode<T> *p);		//�����߶�
		int Count(BiNode<T> *p);  		//��ڵ����
	public:
		BiTree() {
			root = NULL;
		};
		BiTree(vector<T> &pre);//���ݴ���ָ���ǵ��������й��������
		BiTree(vector<T> &pre, vector<T> &mid);
		void PreOrder();	//ǰ�����
		void InOrder();		//�������
		void PostOrder();	//�������
		int Height();		//�����߶�
		int Count();		//��ڵ����

};
template <class T>

BiNode<T> *BiTree<T>::CreateByPre(vector<T> &pre, int &i) {
	T e = pre[i];
	i++;
	if (e == '*') {
		return NULL;
	}
	BiNode<T> *p = new BiNode<T>;
	p->data = e;
	p->lchild = CreateByPre(pre, i); //����������
	p->rchild = CreateByPre(pre, i); //����������
	return p;
}
template <class T>

//�������й��������
BiTree<T>::BiTree(vector<T> &pre) {
	int i = 0;
	root = CreateByPre(pre, i);
}
//�������
template <class T>

void BiTree<T>::PreOrder(BiNode<T> *p) {
	if (p == NULL)
		return;
	cout << p->data;
	PreOrder(p->lchild);		//�������������
	PreOrder(p->rchild);		//�������������

}
template <class T>

void BiTree<T>::PreOrder() {
	PreOrder(root);
}
//�������
template <class T>

void BiTree<T>::InOrder(BiNode<T> *p) {
	if (p == NULL)
		return;
	InOrder(p->lchild);
	cout << p->data;
	InOrder(p->rchild);
}
template <class T>

void BiTree<T>::InOrder() {
	InOrder(root);
}
//�������
template <class T>

void BiTree<T>::PostOrder(BiNode<T> *p) {
	if (p == NULL)
		return;
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout << p->data;
}
template <class T>

void BiTree<T>::PostOrder() {
	PostOrder(root);
}
template <class T>

int BiTree<T>::Height(BiNode<T> *p) {
	if (p == NULL)
		return 0;
	int left = Height(p->lchild);
	int right = Height(p->rchild);
	if (left > right) {
		return left + 1;
	} else {
		return right + 1;
	}
}
template <class T>

int BiTree<T>::Height() {
	return Height(root);
}
template <class T>

int BiTree<T>::Count(BiNode<T> *p) {
	if (p == NULL)
		return 0;
	int left = Count(p->lchild);
	int right = Count(p->rchild);
	return left + right + 1;
}
template <class T>

int BiTree<T>::Count() {
	return Count(root);
}
template <class T>

BiNode<T> *BiTree<T>::CreateByPreMid(vector<T> &pre, vector<T> &mid, int ipre, int imid, int n) {
	if (n == 0)
		return NULL;
	BiNode<T> *p = new BiNode<T>;
	p->data = pre[ipre];
	int i;
	for (i = 0; i < n; i++) {
		if (pre[ipre] == mid[imid + i]) {
			break;
		}
	}
	p->lchild = CreateByPreMid(pre, mid, ipre + 1, imid, i);
	p->rchild = CreateByPreMid(pre, mid, ipre + i + 1, imid + i + 1, n - i - 1);
	return p;
}
template <class T>

BiTree<T>::BiTree(vector<T> &pre, vector<T> &mid) {
	int n = pre.size();
	root = CreateByPreMid(pre, mid, 0, 0, n);
}

int main() {
	char str[] = "abd**e**cf***";
	vector<char> ss;
	for (int i = 0; i < strlen(str); i++) {
		ss.push_back(str[i]);
	}
	BiTree<char> *bitree = new BiTree<char>(ss);
	cout << "������������������" << endl;
	bitree->PreOrder();
	cout << endl;
	cout << "������������������" << endl;
	bitree->InOrder();
	cout << endl;
	cout << "����������ĺ������" << endl;
	bitree->PostOrder();
	cout << endl;
	cout << "�������ĸ߶�Ϊ" << endl;
	cout << bitree->Height() << endl;
	cout << "������������" << endl;
	cout << bitree->Count() << endl;
	char str1[] = "abdecf";
	char str2[] = "dbeafc";
	vector<char> ss1;
	vector<char> ss2;
	for (int i = 0; i < strlen(str1); i++) {
		ss1.push_back(str1[i]);
		ss2.push_back(str2[i]);
	}
	BiTree<char> *bitree1 = new BiTree<char>(ss1, ss2);
	cout << "�������ǰ������abdecf����������abeafc����Ķ������ĺ�������" << endl;
	bitree1->PostOrder();
	return 0;
}


