#include <stdio.h>
#include <stdlib.h>
typedef int bool;//���c����ʹ�ò����� 
#define true 1
#define false 0
typedef int ElementType;//����Ĭ������Ԫ������Ϊ���� 
typedef struct LNode *PtrToLNode;
struct LNode{
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
//���� 
#define ERROR NULL;
Position Find(List L,ElementType X){
	Position p = L;//ָ��L�ĵ�һ���ڵ�
	while(p&&p->Data!=X)
		p = p->Next;
	if(p){
		return p;
	} else{
		return ERROR;
	}
}
//��ͷ���Ĳ���
bool Insert(List L,ElementType X,Position P){
	Position tmp,pre;
	for(pre = L;pre&&pre->Next!=P;pre=pre->Next);
	if(pre==NULL) {
		printf("����λ�ò�������\n");
		return false;
	}else{
		tmp = (Position)malloc(sizeof(struct LNode));
		tmp ->Data = X;
		tmp ->Next = P;
		pre->Next = tmp;
		return true;
	}
}
//��ͷ����ɾ��
bool Delete(List L,Position P){
	Position pre;
	for(pre = L;pre&&pre->Next!=P;pre = pre->Next);
	if(pre == NULL||P==NULL){
		printf("ɾ��λ�ò�������\n");
		return false;
	}else{
		pre->Next = P->Next;
		free(P);
		return true;
	}
} 
int main(){
//	����������
	return 0;
} 
