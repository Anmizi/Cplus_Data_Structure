#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;//¶¨ÒåË«Õ»ÔªËØÀàÐÍ 
struct DStack{
	ElementType *Data;//´æ´¢Ë«Õ»µÄÊý×é 
	int top1;//¶ÑÕ»1µÄÕ»¶¥Ö¸Õë 
	int top2;//¶ÑÕ»2µÄÕ»¶¥Ö¸Õë 
	int MaxSize;//Ë«Õ»¿Õ¼ä´óÐ¡ 
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
		printf("¶ÑÕ»Âú");return;
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
			printf("¶ÑÕ»1¿Õ");
		}else return Ptrs->Data[(Ptrs->top1)--];
	}else{
		if(Ptrs->top2 == Ptrs->MaxSize-1){
			printf("¶ÑÕ»2¿Õ");
		}else return Ptrs->Data[(Ptrs->top2)++];
	}
}
void PrintStack(TwoStack Ptrs,int Tag){
	if(Tag==1){
		if(Ptrs->top1 == 0){
			printf("¶ÑÕ»1¿Õ"); 
		}else {
			while(Ptrs->top1!=0){
				printf("%d ",Ptrs->Data[Ptrs->top1]);
				Ptrs->top1--;
			}
		}
	}else{
		if(Ptrs->top2 == Ptrs->MaxSize-1){
			printf("¶ÑÕ»2¿Õ");
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
	//´òÓ¡¶ÑÕ»1µÄÔªËØ
	printf("´òÓ¡¶ÑÕ»1µÄÔªËØ£º\n");
	PrintStack(stack1,1);
	printf("\n");
	//´òÓ¡¶ÑÕ»2µÄÔªËØ 
	printf("´òÓ¡¶ÑÕ»2µÄÔªËØ£º\n");
	PrintStack(stack1,2);
	return 0;
} 
