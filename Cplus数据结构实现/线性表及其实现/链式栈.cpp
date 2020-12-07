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
		LStack();//构造初始化 
		~LStack();
		void EnStack(T x);//进栈 
		T DeStack();//出栈 
		T Top();//获取栈顶元素 
		bool Empty();//判空 
		void PrintStack();//打印链式栈 
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
		cerr<<"栈空"<<endl;
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
		cerr<<"栈空"<<endl;
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
//	测试主函数
	LStack<int> *lstack = new LStack<int>;
	for(int i=0;i<10;i++){
		lstack->EnStack(i);
	}
	//从栈顶开始打印输出 
	lstack->PrintStack(); 
	lstack->DeStack();
	lstack->DeStack();
	lstack->PrintStack();
	
	return 0;
} 
