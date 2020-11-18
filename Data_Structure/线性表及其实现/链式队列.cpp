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
		//��ͷ�Ͷ�βָ�룬�ֱ�ָ��ͷ�����ն˽ڵ�
		Node<T> *front,*rear;
	public:
		LinkQuene();//���캯��,��ʼ���ն��� 
		~LinkQuene();
		void EnQuene(T x);//��x����� 
		T DeQuene();//���� 
		T GetQuene();//ȡ��ͷԪ�� 
		bool Empty();//�ж϶����Ƿ�Ϊ��	
};
//�����ʼ�� 
template <class T>
LinkQuene<T>::LinkQuene(){
	Node<T> *s = new Node<T>;
	s->next = NULL;
	front=rear=s;
} 
//���
template <class T>
void LinkQuene<T>::EnQuene(T x){
	Node<T> *p = new Node<T>;
	p->data = x;
	p->next = NULL;
	rear->next = p;
	rear = p;
} 
//����
template <class T>
T LinkQuene<T>::DeQuene(){
	if(rear == front){
		cerr<<"����";exit(1);
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
//ȡ��ͷԪ��
template <class T>
T LinkQuene<T>::GetQuene(){
	if(front == rear){
		cerr<<"���п�";exit(1); 
	}
	return front->next->data;
} 
//�п�
template <class T>
bool LinkQuene<T>::Empty(){
	return front == rear;
} 
int main(){
	
	
	return 0;
}
