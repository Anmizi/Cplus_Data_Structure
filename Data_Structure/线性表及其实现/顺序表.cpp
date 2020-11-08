#include <iostream>
using namespace std;
template <class T,int MaxSize>
class SeqList{
	T data[MaxSize];
	int length;
	public:
		SeqList();//构造初始化 
		SeqList(T a[],int n);//有参构造初始化 
		int ListLength();//顺序表长度 
		T Get(int pos);//按位查找 
		int Locate(T item);//按值查找 
		void PrintSeqList();//打印输出顺序表 
		void Insert(int i,T item);//按位插入元素 
		T Delete(int i);//按位删除 
}; 
template <class T,int MaxSize>
SeqList<T,MaxSize>::SeqList(){
	length = 0;
} 
template <class T,int MaxSize>
SeqList <T,MaxSize>::SeqList(T a[],int n){
	if(n>MaxSize){
		cerr<<"参数非法";
		exit(1);
	}
	for(int i=0;i<n;i++){
		data[i] = a[i];
		length = n;
	}
}
//计算长度 
template <class T,int MaxSize>
int SeqList <T,MaxSize>::ListLength(){
	return length;
}
//按位查找 
template <class T,int MaxSize>
T SeqList<T,MaxSize>::Get(int pos){
	if(pos<1||pos>length){
		cerr<<"查找位置非法";
		exit(1); 
	}
	return data[pos-1];
}
//按值查找 
template <class T,int MaxSize>
int SeqList <T,MaxSize>::Locate(T item){
	for(int i = 0;i<length;i++){
		if(data[i] == item){
			return i+1;
		}
	}
	return 0;
}
//打印输出 
template <class T,int MaxSize>
void SeqList<T,MaxSize>::PrintSeqList(){
	for(int i=0;i<length;i++){
		cout<<data[i]<<endl;
	}
}
//插入操作 
template <class T,int MaxSize>
void SeqList<T,MaxSize>::Insert(int i,T item){
	if(length>=MaxSize){
		cerr<<"上溢";
		exit(1); 
	}
	if(i<1||i>length+1){
		cerr<<"插入位置非法";
		exit(1); 
	}
	for(int j=length-1;j>=i-1;j--){
		data[j+1] = data[j];
	}
	data[i-1] = item;
	length++;
} 
//删除操作 
template <class T,int MaxSize>
T SeqList <T,MaxSize>::Delete(int i){
	if(length == 0){
		cerr<<"下溢";
		exit(1); 
	} 
	if(i<1||i>length){
		cerr<<"删除位置非法";
		exit(1);
	}
	T x = data[i-1];
	for(int j=i;j<length;j++){
		data[i-1] = data[i];
	}
	length--;
	return x;
}
//主函数测试 
int main(){
	int arr[12]={1,2,3,4,5,6,7,8,9,10};
	SeqList<int,12> s1(arr,10);
//	s1.PrintSeqList();//测试打印输出 
//	cout<<s1.ListLength()<<endl;//测试表长度 
//	cout<<s1.Get(4)<<endl;//测试按位查找 
//	cout<<s1.Locate(8)<<endl; //测试按值查找 
//	s1.Insert(5,66);//测试插入值 
//	s1.Insert(5,66);
//	s1.PrintSeqList();
//	s1.Delete(5);//测试删除值 
//	s1.Delete(5);
//	s1.PrintSeqList(); 
	
	return 0;
}

