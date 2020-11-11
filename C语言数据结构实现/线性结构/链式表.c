#include <stdio.h>
#include <stdlib.h>
typedef int bool;//解决c不能使用布尔型 
#define true 1
#define false 0
typedef int ElementType;//设置默认链表元素类型为整型 
typedef struct LNode *PtrToLNode;
struct LNode{
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
//查找 
#define ERROR NULL;
Position Find(List L,ElementType X){
	Position p = L;//指向L的第一个节点
	while(p&&p->Data!=X)
		p = p->Next;
	if(p){
		return p;
	} else{
		return ERROR;
	}
}
//带头结点的插入
bool Insert(List L,ElementType X,Position P){
	Position tmp,pre;
	for(pre = L;pre&&pre->Next!=P;pre=pre->Next);
	if(pre==NULL) {
		printf("插入位置参数错误\n");
		return false;
	}else{
		tmp = (Position)malloc(sizeof(struct LNode));
		tmp ->Data = X;
		tmp ->Next = P;
		pre->Next = tmp;
		return true;
	}
}
//带头结点的删除
bool Delete(List L,Position P){
	Position pre;
	for(pre = L;pre&&pre->Next!=P;pre = pre->Next);
	if(pre == NULL||P==NULL){
		printf("删除位置参数错误\n");
		return false;
	}else{
		pre->Next = P->Next;
		free(P);
		return true;
	}
} 
int main(){
//	测试主函数
	return 0;
} 
