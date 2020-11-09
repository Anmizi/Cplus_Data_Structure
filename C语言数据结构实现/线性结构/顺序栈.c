#include <stdio.h>
#include <stdlib.h>
#define ERROR -1;
#define true 1;
#define false 0;
typedef int bool;
typedef int ElementType;
typedef int Position;
struct SNode{
	ElementType *Data; /*�洢Ԫ�ص�����*/ 
	Position Top;	//ջ��Ԫ�� 
	int MaxSize;	//��ջ������� 
};
typedef struct SNode *Stack; 

//������ջ
Stack CreateStack(int MaxSize){
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S; 
}
//�ж��Ƿ���ջ 
bool IsFull(Stack S){
	return (S->Top == S->MaxSize-1);
} 
//��ջ����
bool Push(Stack S,ElementType X){
	if(IsFull(S)){
		printf("��ջ��");
		return false; 
	}else{
		S->Data[++(S->Top)] = X;
		return true;
	}
} 
//�п� 
bool IsEmpty(Stack S){
	return (S->Top == -1);
} 
ElementType Pop(Stack S){
	if(IsEmpty(S)){
		printf("��ջ��");
		return ERROR; //��׼���� 
	}else{
		return (S->Data[(S->Top)--]);
	} 
}
void PrintStack(Stack S){
	if(IsEmpty(S)){
		printf("��ջ��");
		exit(1); 
	}
	int i;
	for(i=0;i<S->Top+1;i++){
		printf("%d ",S->Data[i]);
	}
}
int main(){
	Stack stack = CreateStack(10);
	printf("%d",IsEmpty(stack));
	int i;
	for(i=0;i<10;i++){
		Push(stack,i);
	}
	printf("\n");
	PrintStack(stack);
	return 0;
} 
