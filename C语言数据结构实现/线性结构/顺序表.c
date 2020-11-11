#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
typedef int ElementType;//设置默认元素类型为整型 
typedef int Position;
typedef struct LNode *List; 
#define MaxSize 255 
struct LNode{
	ElementType Data[MaxSize];
	Position Last;
};
//初始化
List MakeEmpty(){
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
} 
//查找
#define ERROR -1
Position Find(List L,ElementType X){
	Position i=0;
	while(i<=L->Last&&L->Data[i]!=X)
		i++;
	if(i>L->Last) return ERROR;
	else return i;
} 

//插入
bool Insert(List L,ElementType X,Position P){
	Position i;
	if(L->Last == MaxSize -1){
		printf("表满");
		return false; 
	}
	if(P<0||P>L->Last+1){
		printf("位置不合法");
		return false;
	}
	for(i=L->Last;i>=P;i--){
		L->Data[i+1] = L->Data[i];
	}
	L->Data[P] = X;
	L->Last++;
	return true;
} 

//删除
bool Delete(List L,Position P){
	Position i;
	if(P<0||P>L->Last){
		printf("位置%d不存在元素");
		return false; 
	}
	for(i=P+1;i<L->Last;i++){
		L->Data[i-1] = L->Data[i];
	}
	L->Last--;
	return true;
} 
int main(){
//	测试主函数 
	
	return 0;
} 
