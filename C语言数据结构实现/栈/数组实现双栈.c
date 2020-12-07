#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;//����˫ջԪ������ 
struct DStack{
	ElementType *Data;//�洢˫ջ������ 
	int top1;//��ջ1��ջ��ָ�� 
	int top2;//��ջ2��ջ��ָ�� 
	int MaxSize;//˫ջ�ռ��С 
}S;
typedef struct DStack *TwoStack;
TwoStack CreateStack(int MaxSize){
	TwoStack stack = (TwoStack)malloc(sizeof(TwoStack));
	stack->Data = (ElementType*)malloc(sizeof(ElementType)*MaxSize);
	stack->top1 = 0;
	stack->top2 = MaxSize-1;
	stack->MaxSize = MaxSize;
	return stack;
}
void Push(TwoStack Ptrs,ElementType item,int Tag){
	if(Ptrs->top2 - Ptrs->top1 == 1){
		printf("��ջ��");return;
	}
	if(Tag == 1){
		Ptrs->Data[++(Ptrs->top1)] = item;
	}else{
		Ptrs->Data[--(Ptrs->top2)] = item;
	}
}
ElementType Pop(TwoStack Ptrs,int Tag){
	if(Tag==1){
		if(Ptrs->top1 == 0){
			printf("��ջ1��");
		}else return Ptrs->Data[(Ptrs->top1)--];
	}else{
		if(Ptrs->top2 == Ptrs->MaxSize-1){
			printf("��ջ2��");
		}else return Ptrs->Data[(Ptrs->top2)++];
	}
}
void PrintStack(TwoStack Ptrs,int Tag){
	if(Tag==1){
		if(Ptrs->top1 == 0){
			printf("��ջ1��"); 
		}else {
			while(Ptrs->top1!=0){
				printf("%d ",Ptrs->Data[Ptrs->top1]);
				Ptrs->top1--;
			}
		}
	}else{
		if(Ptrs->top2 == Ptrs->MaxSize-1){
			printf("��ջ2��");
		}else{
			while(Ptrs->top2!=Ptrs->MaxSize-1){
				printf("%d ",Ptrs->Data[Ptrs->top2]);
				Ptrs->top2++;
			}
		}
	}
}
int main(){
	int i;
	int j=1;
	TwoStack stack1 = CreateStack(20);
	for(i=0;i<10;i++){
		Push(stack1,i,j);
		j=-j;
	}
	//��ӡ��ջ1��Ԫ��
	printf("��ӡ��ջ1��Ԫ�أ�\n");
	PrintStack(stack1,1);
	printf("\n");
	//��ӡ��ջ2��Ԫ�� 
	printf("��ӡ��ջ2��Ԫ�أ�\n");
	PrintStack(stack1,2);
	return 0;
} 
