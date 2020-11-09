#include <stdio.h>
#include <stdlib.h>
#define true 1;
#define false 0;
#define ERROR -1;
typedef int ElementType;
typedef int bool;
struct SNode{
	ElementType Data;
	struct SNode *Next;
};
typedef struct SNode *PtrToSNode;
typedef PtrToSNode Stack;
//������ջ 
Stack CreateStack(){
	//����һ����ջ��ͷ�ڵ㣬���ظýڵ�ָ�� 
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}
//�п� 
bool IsEmpty(Stack S){
	return (S->Next == NULL); 
} 
//��ջ����
bool Push(Stack S,ElementType X){
	PtrToSNode tmpCell;
	tmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	tmpCell->Data = X;
	tmpCell->Next = S->Next;
	S->Next = tmpCell;
	return true;
} 
//��ջ����
ElementType Pop(Stack S){
	PtrToSNode FirstCell;
	ElementType TopElem;
	if(IsEmpty(S)){
		printf("��ջ��");
		return ERROR;
	}else{
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
} 
int main(){
	
	return 0;
}
