#include <stdio.h>
#include <stdlib.h>
#define ERROR -1;
#define true 1;
#define false 0;
typedef int bool;
typedef int ElementType;
typedef int Position;
struct SNode{
	ElementType *Data; /*´æ´¢ÔªËØµÄÊý×é*/ 
	Position Top;	//Õ»¶¥ÔªËØ 
	int MaxSize;	//¶ÑÕ»×î´óÈÝÁ¿ 
};
typedef struct SNode *Stack; 

//´´½¨¿ÕÕ»
Stack CreateStack(int MaxSize){
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S; 
}
//ÅÐ¶ÏÊÇ·ñÂúÕ» 
bool IsFull(Stack S){
	return (S->Top == S->MaxSize-1);
} 
//ÈëÕ»²Ù×÷
bool Push(Stack S,ElementType X){
	if(IsFull(S)){
		printf("¶ÑÕ»Âú");
		return false; 
	}else{
		S->Data[++(S->Top)] = X;
		return true;
	}
} 
//ÅÐ¿Õ 
bool IsEmpty(Stack S){
	return (S->Top == -1);
} 
ElementType Pop(Stack S){
	if(IsEmpty(S)){
		printf("¶ÑÕ»¿Õ");
		return ERROR; //±ê×¼´íÎó 
	}else{
		return (S->Data[(S->Top)--]);
	} 
}
void PrintStack(Stack S){
	if(IsEmpty(S)){
		printf("¶ÑÕ»¿Õ");
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
