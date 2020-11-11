#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
typedef int ElementType;//����Ĭ��Ԫ������Ϊ���� 
typedef int Position;
typedef struct LNode *List; 
#define MaxSize 255 
struct LNode{
	ElementType Data[MaxSize];
	Position Last;
};
//��ʼ��
List MakeEmpty(){
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
} 
//����
#define ERROR -1
Position Find(List L,ElementType X){
	Position i=0;
	while(i<=L->Last&&L->Data[i]!=X)
		i++;
	if(i>L->Last) return ERROR;
	else return i;
} 

//����
bool Insert(List L,ElementType X,Position P){
	Position i;
	if(L->Last == MaxSize -1){
		printf("����");
		return false; 
	}
	if(P<0||P>L->Last+1){
		printf("λ�ò��Ϸ�");
		return false;
	}
	for(i=L->Last;i>=P;i--){
		L->Data[i+1] = L->Data[i];
	}
	L->Data[P] = X;
	L->Last++;
	return true;
} 

//ɾ��
bool Delete(List L,Position P){
	Position i;
	if(P<0||P>L->Last){
		printf("λ��%d������Ԫ��");
		return false; 
	}
	for(i=P+1;i<L->Last;i++){
		L->Data[i-1] = L->Data[i];
	}
	L->Last--;
	return true;
} 
int main(){
//	���������� 
	
	return 0;
} 
