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
		void PreOrder(BiNode<T> *p);	//前序遍历
		void InOrder(BiNode<T> *p);		//中序遍历
		void PostOrder(BiNode<T> *p);	//后序遍历
		int Height(BiNode<T> *p);		//求树高度
		int Count(BiNode<T> *p);  		//求节点个数
	public:
		BiTree() {
			root = NULL;
		};
		BiTree(vector<T> &pre);//根据带空指针标记的先序序列构造二叉树
		BiTree(vector<T> &pre, vector<T> &mid);
		void PreOrder();	//前序遍历
		void InOrder();		//中序遍历
		void PostOrder();	//后序遍历
		int Height();		//求树高度
		int Count();		//求节点个数

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
	p->lchild = CreateByPre(pre, i); //创建左子树
	p->rchild = CreateByPre(pre, i); //创建右子树
	return p;
}
template <class T>

//先序序列构造二叉树
BiTree<T>::BiTree(vector<T> &pre) {
	int i = 0;
	root = CreateByPre(pre, i);
}
//先序遍历
template <class T>

void BiTree<T>::PreOrder(BiNode<T> *p) {
	if (p == NULL)
		return;
	cout << p->data;
	PreOrder(p->lchild);		//先序遍历左子树
	PreOrder(p->rchild);		//先序遍历右子树

}
template <class T>

void BiTree<T>::PreOrder() {
	PreOrder(root);
}
//中序遍历
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
//后序遍历
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
	cout << "输出二叉树的先序遍历" << endl;
	bitree->PreOrder();
	cout << endl;
	cout << "输出二叉树的中序遍历" << endl;
	bitree->InOrder();
	cout << endl;
	cout << "输出二叉树的后序遍历" << endl;
	bitree->PostOrder();
	cout << endl;
	cout << "二叉树的高度为" << endl;
	cout << bitree->Height() << endl;
	cout << "二叉树结点个数" << endl;
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
	cout << "输出根据前序序列abdecf和中序序列abeafc构造的二叉树的后序序列" << endl;
	bitree1->PostOrder();
	return 0;
}


