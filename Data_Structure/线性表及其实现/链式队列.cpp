#include <iostream>
using namespace std;
template <class T>
struct Node{
	T data;
	Node<T> *next;
};
template <class T>
class LinkQuene{
	private:
		//队头和队尾指针，分别指向头结点和终端节点
		Node<T> *front,*rear;
	public:
		LinkQuene();//构造函数,初始化空队列 
		~LinkQuene();
		void EnQuene(T x);//将x入队列 
		T DeQuene();//出队 
		T GetQuene();//取队头元素 
		bool Empty();//判断队列是否为空	
};
//构造初始化 
template <class T>
LinkQuene<T>::LinkQuene(){
	Node<T> *s = new Node<T>;
	s->next = NULL;
	front=rear=s;
} 
//入队
template <class T>
void LinkQuene<T>::EnQuene(T x){
	Node<T> *p = new Node<T>;
	p->data = x;
	p->next = NULL;
	rear->next = p;
	rear = p;
} 
//出队
template <class T>
T LinkQuene<T>::DeQuene(){
	if(rear == front){
		cerr<<"下溢";exit(1);
	}
	Node<T> *p = front->next;
	T x = p->data;
	front->next = p->next;
	if(p->next==NULL){
		rear = front;
	}
	delete p;
	return x;
} 
//取队头元素
template <class T>
T LinkQuene<T>::GetQuene(){
	if(front == rear){
		cerr<<"队列空";exit(1); 
	}
	return front->next->data;
} 
//判空
template <class T>
bool LinkQuene<T>::Empty(){
	return front == rear;
} 
int main(){
	
	
	return 0;
}
