#include <iostream>
using namespace std;
template <class T>
struct Node{
	T data;
	Node<T> *next; 
};
template <class T>
class LStack{
	Node<T> *top;
	public:
		LStack();//�����ʼ�� 
		~LStack();
		void EnStack(T x);//��ջ 
		T DeStack();//��ջ 
		T Top();//��ȡջ��Ԫ�� 
		bool Empty();//�п� 
		void PrintStack();//��ӡ��ʽջ 
};
template <class T>
LStack<T>::LStack(){
	top = NULL;
} 
template <class T>
void LStack<T>::EnStack(T x){
	Node<T> *s = new Node<T>;
	s->data = x;
	s->next = top;
	top = s;
} 
template <class T>
T LStack<T>::DeStack(){
	if(!top){
		cerr<<"ջ��"<<endl;
		exit(1);
	}
	Node<T> *p = top;
	top = top->next;
	T x = p->data;
	delete p;
	return x;
}
template <class T>
bool LStack<T>::Empty(){
	return top == NULL;
}
template <class T>
T LStack<T>::Top(){
	if(!top){
		cerr<<"ջ��"<<endl;
		exit(1);
	}
	return top->data;
}
template <class T>
LStack<T>::~LStack(){
	Node<T> *p = top;
	while(p){
		Node<T> *q = p;
		p = p->next;
		delete q;
	} 
	top = NULL;
}
template <class T>
void LStack<T>::PrintStack(){
	Node<T> *p = top; 
	while(p){
		cout<<p->data<<" ";
		p = p->next; 
	}
	cout<<endl;
} 
int main(){
//	����������
	LStack<int> *lstack = new LStack<int>;
	for(int i=0;i<10;i++){
		lstack->EnStack(i);
	}
	//��ջ����ʼ��ӡ��� 
	lstack->PrintStack(); 
	lstack->DeStack();
	lstack->DeStack();
	lstack->PrintStack();
	
	return 0;
} 
