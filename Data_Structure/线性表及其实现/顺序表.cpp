#include <iostream>
using namespace std;
template <class T,int MaxSize>
class SeqList{
	T data[MaxSize];
	int length;
	public:
		SeqList();//�����ʼ�� 
		SeqList(T a[],int n);//�вι����ʼ�� 
		int ListLength();//˳����� 
		T Get(int pos);//��λ���� 
		int Locate(T item);//��ֵ���� 
		void PrintSeqList();//��ӡ���˳��� 
		void Insert(int i,T item);//��λ����Ԫ�� 
		T Delete(int i);//��λɾ�� 
}; 
template <class T,int MaxSize>
SeqList<T,MaxSize>::SeqList(){
	length = 0;
} 
template <class T,int MaxSize>
SeqList <T,MaxSize>::SeqList(T a[],int n){
	if(n>MaxSize){
		cerr<<"�����Ƿ�";
		exit(1);
	}
	for(int i=0;i<n;i++){
		data[i] = a[i];
		length = n;
	}
}
//���㳤�� 
template <class T,int MaxSize>
int SeqList <T,MaxSize>::ListLength(){
	return length;
}
//��λ���� 
template <class T,int MaxSize>
T SeqList<T,MaxSize>::Get(int pos){
	if(pos<1||pos>length){
		cerr<<"����λ�÷Ƿ�";
		exit(1); 
	}
	return data[pos-1];
}
//��ֵ���� 
template <class T,int MaxSize>
int SeqList <T,MaxSize>::Locate(T item){
	for(int i = 0;i<length;i++){
		if(data[i] == item){
			return i+1;
		}
	}
	return 0;
}
//��ӡ��� 
template <class T,int MaxSize>
void SeqList<T,MaxSize>::PrintSeqList(){
	for(int i=0;i<length;i++){
		cout<<data[i]<<endl;
	}
}
//������� 
template <class T,int MaxSize>
void SeqList<T,MaxSize>::Insert(int i,T item){
	if(length>=MaxSize){
		cerr<<"����";
		exit(1); 
	}
	if(i<1||i>length+1){
		cerr<<"����λ�÷Ƿ�";
		exit(1); 
	}
	for(int j=length-1;j>=i-1;j--){
		data[j+1] = data[j];
	}
	data[i-1] = item;
	length++;
} 
//ɾ������ 
template <class T,int MaxSize>
T SeqList <T,MaxSize>::Delete(int i){
	if(length == 0){
		cerr<<"����";
		exit(1); 
	} 
	if(i<1||i>length){
		cerr<<"ɾ��λ�÷Ƿ�";
		exit(1);
	}
	T x = data[i-1];
	for(int j=i;j<length;j++){
		data[i-1] = data[i];
	}
	length--;
	return x;
}
//���������� 
int main(){
	int arr[12]={1,2,3,4,5,6,7,8,9,10};
	SeqList<int,12> s1(arr,10);
//	s1.PrintSeqList();//���Դ�ӡ��� 
//	cout<<s1.ListLength()<<endl;//���Ա��� 
//	cout<<s1.Get(4)<<endl;//���԰�λ���� 
//	cout<<s1.Locate(8)<<endl; //���԰�ֵ���� 
//	s1.Insert(5,66);//���Բ���ֵ 
//	s1.Insert(5,66);
//	s1.PrintSeqList();
//	s1.Delete(5);//����ɾ��ֵ 
//	s1.Delete(5);
//	s1.PrintSeqList(); 
	
	return 0;
}

