#include <stdio.h>
struct Two_way_Stack{
	type_ * Store;
	int len;
	int top1;
	int top2;
}; 
typedef Two_way_Stack* Tstack; 
//³õÊ¼»¯Ë«ÏòÕ»
int initstack(Tstack stack,int len){
	stack  = (Tstack)malloc(sizeof(struct Two_way_Stack));
	stack->len = len;
	stack->Store = (type_*)malloc(len*sizeof(type_));
	stack->top1=0;
	stack->top2 = (len-1);
}		
int main(){
	return 0;
} 
