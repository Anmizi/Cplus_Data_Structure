#include <iostream>
using namespace std;
//定义节点类型 
template <class T>
struct Node{
	T data;
	Node<T> *next;//存储下个节点地址 
};
template <class T>
class Linklist{
	Node<T> *head;//头节点指针 
	public:
		Linklist();
		Linklist(T a[],int n);
		~Linklist();
		int ListLength();//计算长度 
		T Get(int pos);//按位查找 
		int locate(T item);//按值查找 
		void PrintLinkList();//打印输出单链表 
		void Insert(int i,T item);//插入操作 
		T Delete(int i);//删除操作 
};
template <class T>
Linklist<T>::Linklist(){
	head = new Node<T>;
	head->next=NULL;
}
template <class T>
Linklist<T>::Linklist(T a[],int n){
	head = new Node<T>;
	Node<T> *rear = head;
	for(int i=0;i<n;i++){
		Node<T> *s = new Node<T>;
		s->data = a[i];
		rear->next = s;
		rear = s;
	}
	rear->next = NULL;
}
//计算长度 
template <class T>
int Linklist<T>::ListLength(){
	int num = 0;
	Node<T> *p = head->next;
	while(p){
		p=p->next;
		num++;
	}
	return num;
}
//按位查找 
template <class T>
T Linklist<T>::Get(int pos){
	Node<T> *p = head->next;
	int j=1;
	while(p&&j<pos){
		p = p->next;
		j++;
	}
	if(!p||j>pos){
		cerr<<"查找位置非法";
		exit(1); 
	}
	else{
		return p->data;
	}
}
//按值查找 
template <class T>
int Linklist<T>::locate(T item){
	Node<T> *p = head->next;
	int j=1;
	while(p&&p->data!=item){
		p=p->next;
		j++;
	}
	if(p){
		return j;
	}else{
		return 0;
	}
}
//打印输出 
template <class T>
void Linklist<T>::PrintLinkList(){
	Node<T> *p = head->next;
	while(p){
		cout<<p->data<<endl;
		p = p->next;
	}
}
//插入操作 
template <class T>
void Linklist<T>::Insert(int i,T item){
	Node<T> *p = head;
	int j=0;
	while(p&&j<i-1){
		p = p->next;
		j++;
	}
	if(!p){
		cerr<<"插入位置非法 ";
		exit(1);
	}else{
		Node<T> *s = new Node<T>;
		s->data=item;
		s->next=p->next;
		p->next=s;
	}
}
//删除操作 
template <class T>
T Linklist<T>::Delete(int i){
	Node<T> *p=head;
	int j=0;
	while(p&&j<i-1){
		p = p->next;
		j++;
	}
	if(!p||!p->next){
		cerr<<"删除位置非法";
		exit(1);
		 
	}else{
		Node<T> *q = p->next;
		T x=q->data;
		p->next=q->next;
		delete q;
		return x;
	}
} 
template <class T>
Linklist<T>::~Linklist(){
	Node<T> *p = head;
	while(p){
		Node<T> *q = p;
		p = p->next;
		delete q;
	}
	head = NULL;
}
//主函数测试 
int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	Linklist<int> *link1 = new Linklist<int>(a,10);
//	link1->PrintLinkList();
	return 0;
} 
