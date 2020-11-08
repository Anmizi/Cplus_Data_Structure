#include <iostream>
using namespace std;
//����ڵ����� 
template <class T>
struct Node{
	T data;
	Node<T> *next;//�洢�¸��ڵ��ַ 
};
template <class T>
class Linklist{
	Node<T> *head;//ͷ�ڵ�ָ�� 
	public:
		Linklist();
		Linklist(T a[],int n);
		~Linklist();
		int ListLength();//���㳤�� 
		T Get(int pos);//��λ���� 
		int locate(T item);//��ֵ���� 
		void PrintLinkList();//��ӡ��������� 
		void Insert(int i,T item);//������� 
		T Delete(int i);//ɾ������ 
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
//���㳤�� 
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
//��λ���� 
template <class T>
T Linklist<T>::Get(int pos){
	Node<T> *p = head->next;
	int j=1;
	while(p&&j<pos){
		p = p->next;
		j++;
	}
	if(!p||j>pos){
		cerr<<"����λ�÷Ƿ�";
		exit(1); 
	}
	else{
		return p->data;
	}
}
//��ֵ���� 
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
//��ӡ��� 
template <class T>
void Linklist<T>::PrintLinkList(){
	Node<T> *p = head->next;
	while(p){
		cout<<p->data<<endl;
		p = p->next;
	}
}
//������� 
template <class T>
void Linklist<T>::Insert(int i,T item){
	Node<T> *p = head;
	int j=0;
	while(p&&j<i-1){
		p = p->next;
		j++;
	}
	if(!p){
		cerr<<"����λ�÷Ƿ� ";
		exit(1);
	}else{
		Node<T> *s = new Node<T>;
		s->data=item;
		s->next=p->next;
		p->next=s;
	}
}
//ɾ������ 
template <class T>
T Linklist<T>::Delete(int i){
	Node<T> *p=head;
	int j=0;
	while(p&&j<i-1){
		p = p->next;
		j++;
	}
	if(!p||!p->next){
		cerr<<"ɾ��λ�÷Ƿ�";
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
//���������� 
int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	Linklist<int> *link1 = new Linklist<int>(a,10);
//	link1->PrintLinkList();
	return 0;
} 
