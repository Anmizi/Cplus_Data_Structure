#include <stdio.h>
//�������
void Inorder(BinTree BT){
	if(BT){
		Inorder(BT->Left);
		printf("%d ",BT->Data);
		Inorder(BT->Right);
	}
} 
//ǰ�����
void Preorder(BinTree BT){
	if(BT){
		printf("%d ",BT->Data);
		Preorder(BT->Left);
		Preorder(BT->Right);
	}
} 
//�������
void Postorder(BinTree BT){
	if(BT){
		Postorder(BT->Left);
		Postorder(BT->Right);
		printf("%d ",BT->Data);
	}
} 
//��α���
void Levelorder(BinTree BT){
	Quene Q;
	BinTree T;
	if(!BT) return ;
	Q = CreateQuene();
	AddQ(Q,BT);
	while(!IsEmpty(Q)){
		T = DeleteQ(Q);
		printf("%d ",T->Data);
		if(T->Left) AddQ(Q,T->Left);
		if(T->Right) AddQ(Q,T->Right);
	}
}
int main(){
//  �Ĵ��벻��ֱ�ӱ������� 
//	�������޸Ĵ�����в��� 
	return 0;
} 
