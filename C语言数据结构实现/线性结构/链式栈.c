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
//创建空栈 
Stack CreateStack(){
	//构建一个堆栈的头节点，返回该节点指针 
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}
//判空 
bool IsEmpty(Stack S){
	return (S->Next == NULL); 
} 
//入栈操作
bool Push(Stack S,ElementType X){
	PtrToSNode tmpCell;
	tmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	tmpCell->Data = X;
	tmpCell->Next = S->Next;
	S->Next = tmpCell;
	return true;
} 
//出栈操作
ElementType Pop(Stack S){
	PtrToSNode FirstCell;
	ElementType TopElem;
	if(IsEmpty(S)){
		printf("堆栈空");
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
